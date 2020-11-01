#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int wczytaj(FILE *fin, float tablica[][100])
{
    int wiersz = 0;
    int kolumna = 0;
    float liczba = 0;

    fscanf(fin, "%d %d", &wiersz, &kolumna);

    for(int i = 0; i < wiersz; i++)
    {
        for(int j = 0; j  <kolumna; j++)
        {
            fscanf(fin, "%f", &liczba);
            tablica[i][j] = liczba; //  przypisanie liczby to tablicy na miejsce i i j
        }
    }
    return wiersz;
}

void iloczyn(float macierz[][100], float wektor[][100], int wiersz1, int wiersz2)
{
    float wynik = 0;
    printf("[ ");
    for (int i = 0; i < wiersz1; i++)
    {
        for (int j = 0; j < wiersz2; j++)
        {
            wynik += macierz[i][j] * wektor[j][0];
        }
        printf("%f ", wynik);
        wynik = 0; // zerowanie po kazdym wierszu
    }
    printf ("]\n");
}

int main (int argc, char *argv[])
{
    FILE *fin1;
    FILE *fin2;

    float macierz[100][100];
    float wektor[100][100];

    int wiersz1;
    int wiersz2;
    
    fin1 = fopen(argv[1], "r");
    fin2 = fopen(argv[2], "r");

    wiersz1 = wczytaj(fin1, macierz);
    wiersz2 = wczytaj(fin2, wektor);

    printf("(%d) ", wiersz1);
    iloczyn(macierz, wektor, wiersz1, wiersz2);

    return 0;
}