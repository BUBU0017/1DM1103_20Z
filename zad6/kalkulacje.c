#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"

float norm(macierz *m)
{
    float s = 0;

    for (int i = 0; i < m->w; i++) {
        for (int j = 0; j < m->k; j++) {
            s += m->tab[i][j] * m->tab[i][j];
        }
    }
    return sqrt(s);
}

macierz *suma(macierz *macA, macierz *macB)
{
    macierz *wynik;
    wynik = (macierz*) malloc(sizeof(macierz));
    wynik->w=macA->w;
    wynik->k=macA->k;

wynik->tab = (float**) malloc(sizeof(float*) * wynik->w);
    for(int i = 0; i < wynik->w; i++){
        wynik->tab[i] = (float*) malloc(sizeof(float) * wynik->k);
        for(int j = 0; j < wynik->k; j++)
            wynik->tab[i][j] = macA->tab[i][j] + macB->tab[i][j];}
    
    return wynik;
}

macierz *roznica(macierz *macA, macierz *macB)
{
    macierz *suma;
    suma = (macierz*) malloc(sizeof(macierz));
    suma->w=macA->w;
    suma->k=macA->k;

suma->tab = (float**) malloc(sizeof(float*) * suma->w);
    for(int i = 0; i < suma->w; i++){
        suma->tab[i] = (float*) malloc(sizeof(float) * suma->k);
        for(int j = 0; j < suma->k; j++)
            suma->tab[i][j] = macA->tab[i][j] - macB->tab[i][j];}
    
    return suma;
}

macierz *wymnozSkalar(macierz *macA, float n)
{
    macierz *wynik;
    wynik = (macierz*) malloc(sizeof(macierz));
    wynik->w=macA->w;
    wynik->k=macA->k;

wynik->tab = (float**) malloc(sizeof(float*) * wynik->w);
    for(int i = 0; i < wynik->w; i++){
        wynik->tab[i] = (float*) malloc(sizeof(float) * wynik->k);
        for(int j = 0; j < wynik->k; j++)
            wynik->tab[i][j] = (macA->tab[i][j] * n);}
    
    return wynik;
}

macierz *wymnozMacierz(macierz *macA, macierz *macB)
{   
    macierz *wynik;
    wynik = (macierz*) malloc(sizeof(macierz));
        wynik->w = macA->w;
        wynik->k = macB->k;

        wynik->tab = (float**) malloc(sizeof(float*) * wynik->w);
        for(int i=0; i<macA->w; i++){
        wynik->tab[i] = (float*) malloc(sizeof(float) * wynik->k);
            for(int j=0; j<macB->k; j++)
                for(int x=0; x<macA->k; x++)
                {
                    wynik->tab[i][j] += macA->tab[i][x] * macB->tab[x][j];
                }
        }
        return wynik; 
}
