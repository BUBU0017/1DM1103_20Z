#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz 
{
    int w;
    int k;
    float tab[200][200];
};

void wczytaj(FILE * fin, struct macierz *m)
{
    int i,j;
    fscanf(fin, "%d", &m->w);
    fscanf(fin, "%d", &m->k);

    for (i=0; i < m->w; i++)
    {
        for (j=0; j < m->k; j++)
        {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void wypisz(struct macierz m)
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.w; i++)
    {
        for (j=0; j < m.k; j++)
        {
            printf("%5.1f ", m.tab[i][j]);
        }
        if (i < (m.w-1))
            printf("\n  ");
    }
    printf("]\n");
}

float norm(struct macierz m)
{
    float suma = 0;
    int i,j;

    for (i = 0; i < m.w; i++)
    {
        for (j=0; j < m.k; j++)
        {
            suma += sqrt(m.tab[i][j] * m.tab[i][j]);
        }
    }
    return suma;
}

/* struct macierz suma(struct macierz m, struct macierz n)
{
    struct macierz suma;
    int i,j;
    suma.w = m.w;
    suma.k = m.k;
    /* if (suma.w != n.w || suma.k != n.k)
    {
        printf("Dodawanie nie jest możliwe dla podanych macierzy!\n");
        exit(-1);
    }
    for (i = 0; i < m.w; i++)
        {
            for (j=0; j < m.k; j++)
            {
                suma.tab[i][j] = m.tab[i][j] + n.tab[i][j];
            }
        }
        return suma;
}
*/
struct macierz suma(struct macierz m, struct macierz n)
{
    struct macierz suma;
    suma.w = m.w;
    suma.k = m.k;
    for (int i = 0; i < m.w; i++) {
        for (int j=0; j < m.k; j++) {
            suma.tab[i][j] = m.tab[i][j] + n.tab[i][j];
        }
    }
    return suma;
}

struct macierz roznica(struct macierz m, struct macierz n)
{
    struct macierz roznica;
    int i,j;
    roznica.w = m.w;
    roznica.k = m.k;

    for (i = 0; i < m.w; i++)
    {
        for (j=0; j < m.k; j++)
        {
            roznica.tab[i][j] = m.tab[i][j] - n.tab[i][j];
        }
    }
    return roznica;
}

struct macierz wymnozSkalar(struct macierz m, float n)
{
    struct macierz wymnoz;
    int i,j;
    wymnoz.w = m.w;
    wymnoz.k = m.k;

    for (i = 0; i < m.w; i++)
    {
        for (j=0; j < m.k; j++)
        {
            wymnoz.tab[i][j] = m.tab[i][j] * n;
        }
    }
    return wymnoz;
}
struct macierz wymnozMacierz(struct macierz m, struct macierz n)
{
    struct macierz iloczyn;
    iloczyn.w = m.w;
    iloczyn.k = n.k;
    int i, j;

    for(i = 0; i < m.w; i++)
    {
        for(j = 0; j < n.k; j++)
        {
            iloczyn.tab[i][j] = 0;
            for(int x = 0; x<m.k; x++)
            {
                iloczyn.tab[i][j] += m.tab[i][x] * n.tab[x][j];     
            }
        }
    }        
    return iloczyn;
}
/*
struct macierz wymnozMacierz(struct macierz m, struct macierz n)
{
    struct macierz iloczyn;
    int i,j;
    iloczyn.w = m.w;
    iloczyn.k = n.k;

    for (i = 0; i < m.w; i++)
    {
        for (j=0; j < m.k; j++)
        {
            for (int x = 0; x < m.k; x++)
            {
                iloczyn.tab[i][j] += m.tab[i][x] * n.tab[x][j];
            }
        }
    }
    return iloczyn;
}   
*/
/*
void zapisz(FILE *h, struct macierz m)
{
    fprintf(h,"%d\n%d\n", m.w, m.k);
    for (int i = 0; i < m.w; i++)
    {
        for (int j=0; j < m.k; j++)
        {
            fprintf(h,"%f\n", m.tab[i][j]);
        }
    }

    fclose(h);
}
*/
void zapisz(char nazwa[], struct macierz m)
{
    FILE *fout;
    fout = fopen(nazwa, "w");
    int i,j;
 
    fprintf(fout, "%d\n%d\n", m.w, m.k);
    for (i = 0; i < m.w; i++)
    {
        for (j=0; j < m.k; j++)
        {
            fprintf(fout, "%.1f\n", m.tab[i][j]);
        }
            
    }
    fclose(fout);
}

void zapiszL(char nazwa[], float m)
{
    FILE *fout;
    fout = fopen(nazwa, "w");
    fprintf(fout, "Norma macierzy wynosi = %f\n", m);
    fclose(fout);
}

int main(int argc, char *argv[])
{   
    struct macierz macA;
    struct macierz macB;
    FILE * finA;
    FILE * finB;

    if(strcmp(argv[1], "sum") == 0)
    {
        finA = fopen(argv[2], "r");
        finB = fopen(argv[3], "r");
        wczytaj(finB, &macB);
        wczytaj(finA, &macA);
        fclose(finA);
        fclose(finB);

        if((macA.w!=macB.w) || (macA.k!=macB.k))
        {
            printf("Dodawanie nie jest możliwe dla podanych macierzy!\n");
            exit(-2);
        }

        else if(argc==5)
        {
            zapisz(argv[4], suma(macA, macB));
        }
        
        else if (argc == 4)
        {
           wypisz(suma(macA, macB)); 
        }

        else
        {
            printf("O czymś zapomniałeś!\n");
            exit(-1);
        }   
    }

    else if(strcmp(argv[1], "subtract") == 0)
    {
        finA = fopen(argv[2], "r");
        finB = fopen(argv[3], "r");
        wczytaj(finA, &macA);
        wczytaj(finB, &macB);
        fclose(finA);
        fclose(finB);

        if((macA.w!=macB.w) || (macA.k!=macB.k))
        {
            printf("Odejmowanie nie jest możliwe dla podanych macierzy!\n");
            exit(-3);
        }

        else if (argc == 5)
        {
            zapisz(argv[4], roznica(macA, macB));
        }
        
        else if(argc == 4)
        {
            wypisz(roznica(macA, macB));
        }

        else
        {
            printf("O czymś zapomniałeś!\n");
            exit(-1);
        }
    }

    else if (strcmp(argv[1], "prod") == 0) 
    {
        finA = fopen(argv[2], "r");
        finB = fopen(argv[3], "r");
        wczytaj(finA, &macA);
        wczytaj(finB, &macB);        
        fclose(finA);
        fclose(finB);

        if(macA.w != macB.k)
        {
            printf("Mnożenie nie jest możliwe dla podanych macierzy!\n");
            exit(-4);
        }

        else if (argc == 5)
        {
            zapisz(argv[4], wymnozMacierz(macA, macB));
        }

        else if(argc == 4)
        {
            wypisz(wymnozMacierz(macA, macB)); 
        }

        else
        {
            printf("O czymś zapomniałeś!\n");
            exit(-1);
        }
    }

    else if ( strcmp( argv[1], "multiply") == 0) 
    {
        finA = fopen(argv[2], "r");
        wczytaj(finA, &macA);
        fclose(finA);
        float skalar;
        skalar = atof(argv[3]);

        if (argc == 5)
        {
            zapisz(argv[4], wymnozSkalar(macA, skalar));
        }

        else if (argc == 4)
        {
            wypisz(wymnozSkalar(macA, skalar));
        }

        else
        {
            printf("O czymś zapomniałeś!\n");
            exit(-1);
        } 
    }
 
    else if(strcmp(argv[1], "norm") == 0)
    {
        finA  = fopen(argv[2], "r");
        wczytaj(finA, &macA);
        fclose(finA);
        if(argc == 3)
        {
            printf("Norma macierzy pochodzącej z pliku wynosi %s = %f\n", argv[2],norm(macA));
        }
        
        else if(argc==4)
        {
           zapiszL(argv[3], norm(macA)); 
        }
        
        else
        {
            printf("O czymś zapomniałeś!\n");
            exit(-1);
        }     
    }
 
    return 0;
}