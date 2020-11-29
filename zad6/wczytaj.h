#ifndef _wczytaj_h
#define _wczytaj_h

typedef struct _macierz {
    int w;
    int k;
    float **tab;
} macierz;

macierz *wczytaj(FILE * fin);
macierz *wypisz(macierz *m);
void zapisz(char nazwa[], macierz *m);
void zapiszF(char nazwa[], float n);
void zwolnij(macierz *m);

#endif