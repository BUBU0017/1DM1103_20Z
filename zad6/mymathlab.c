#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "kalkulacje.h"


int main(int argc, char *argv[])
{
    FILE * fin;
    macierz *macA;
    macierz *macB;
        
    fin  = fopen(argv[2], "r");
    macA = wczytaj(fin);

    if ( strcmp( argv[1], "norm") == 0)
    {
        float i = norm(macA);

        if(argc == 4)
        {
            zapiszF(argv[3], i);
        }

        else
        {
            printf("Norma macierzy %s wynosi: %f", argv[2], i);
            printf("\n");
        }
    }

    else if ( strcmp( argv[1], "sum") == 0)
    {
        fin  = fopen(argv[3], "r");
        macB = wczytaj(fin);

        if(macA->w == macB->w && macA->k == macB->k)
        {
            if(argc ==5)
            {
                zapisz(argv[4], suma(macA, macB));
            }

            else
            {
                printf("Suma macierzy %s i %s wynosi:\n", argv[2], argv[3]);
                wypisz(suma(macA, macB));
            }
        }

        else
        {
            printf("Nie mogę dodać tych macierzy\n");
        }
        zwolnij(macB);
    } 

    else if ( strcmp( argv[1], "subtract") == 0)
    {
        fin  = fopen(argv[3], "r");
        macB = wczytaj(fin);

        if(macA->w == macB->w && macA->k == macB->k)
        {
            if(argc ==5)
            {
                zapisz(argv[4], roznica(macA, macB));
            }

            else
            {
                printf("Roznica macierzy %s i %s wynosi:\n", argv[2], argv[3]);
                wypisz(roznica(macA, macB));
            }
        }

        else
        {
            printf("Nie mogę odjąć tych macierzy\n");
        }
        zwolnij(macB);
    }

    else if ( strcmp( argv[1], "prod") == 0)
    {
        fin  = fopen(argv[3], "r");
        macB = wczytaj(fin);

        if(macA->k == macB->w)
        {
            if(argc ==5)
            {
                zapisz(argv[4], wymnozMacierz(macA, macB));
            }

            else
            {
                printf("Iloczyn macierzy %s i %s =\n", argv[2], argv[3]);
                wypisz(wymnozMacierz(macA, macB));
            }
        }

        else
        {
            printf("Nie mogę wymnożyć tych macierzy\n");
        }
        zwolnij(macB);
    } 

    else if ( strcmp( argv[1], "multiply") == 0)
    {

        if(argc ==5)
        {
            zapisz(argv[4], wymnozSkalar(macA, atof(argv[3])));
        }
        else
        {
            printf("Iloczyn macierzy %s * %s =\n", argv[2], argv[3]);
            wypisz(wymnozSkalar(macA, atof(argv[3])));
        }
    } 

    else
    {
        printf("Nie rozumiem cię człowieku\n");
    }    
    zwolnij(macA);
   
    return 0;
}
