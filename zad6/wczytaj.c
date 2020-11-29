#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"

macierz *wczytaj(FILE *fin) {
    macierz *ms;
    int i,j;
    ms = (macierz*) malloc(sizeof(macierz));
    fscanf(fin, "%d", &ms->w);
    fscanf(fin, "%d", &ms->k);

  ms->tab = (float**) malloc(sizeof(float*) * ms->w);
    for (i=0;i<ms->w;i++) {
        ms->tab[i] = (float*) malloc(sizeof(float) * ms->k);}
        for (i=0;i<ms->w;i++){
            for (j=0;j< ms->k; j++)
            fscanf(fin, "%f", &ms->tab[i][j]);
    }
    fclose(fin);
    return ms;
}
       
macierz *wypisz(macierz *m) {
    printf("[ ");
    for (int i = 0; i < m->w; i++) {
        for (int j = 0; j < m->k; j++) {
            printf("%5.1f ", m->tab[i][j]);
        }
        if (i < (m->w-1))
            printf("\n  ");
    }
    printf(" ]\n");
    return m;
}

void zapisz(char nazwa[], macierz *m) {
    
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%d\n%d\n", m->w, m->k);

    for (int i = 0; i < m->w; i++) {
        for (int j = 0; j < m->k; j++) {
            fprintf(fout, "%.f\n", m->tab[i][j]);
        }
    }

    fclose(fout);
}

void zapiszF(char nazwa[], float n) {
  
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%f\n", n);
    fclose(fout);
}

void zwolnij(macierz *m){
    for (int i = 0; i < m->w; i++) 
        free( m->tab[i] );
    free(m->tab);
    free(m);
}