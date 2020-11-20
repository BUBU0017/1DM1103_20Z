#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"


int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);

if(strcmp(argv[2], "przedmioty")==0){
najtrudniejszyPrzedmiot(dane, ile);
najlatwiejszyPrzedmiot(dane, ile);
}

else if(strcmp(argv[2], "student")==0)
najlepszy_student(dane,ile);
}