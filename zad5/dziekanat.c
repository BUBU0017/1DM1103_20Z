#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"

void najlatwiejszyPrzedmiot(student dane[100], int ile_rekordow)
{
    char kod_przed[100][10];
    char nazwa_przed[100][255];
    int ilePrzedmiotow;
    float srednia[100];
    for(int j = 0; j<100; j++)
        srednia[j]=0;
    int ileDodawan[100];
    for(int j = 0; j<100; j++)
        ileDodawan[j]=0;
    int i;
    int pozycja;
    int najlepszaPozycja;
    float najlepsza = 0.0f;

    ilePrzedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);
    for (i=0; i < ile_rekordow; i++)
    {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ilePrzedmiotow );
        strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);
        ileDodawan[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }

    for (i=0; i < ilePrzedmiotow; i++)
    {
        srednia[i] = srednia[i]/ileDodawan[i];
    }   
    
  // for (i=0;i<ile_przedmiotow; i++) 
  // printf("Przedmiot [%d] %s : %s średnia: %f\n", i+1, nazwa_przed[i], kod_przed[i], srednia[i]);

    for (i=0; i < ilePrzedmiotow; i++)
    {
        if (najlepsza < srednia[i])
        {
            najlepsza = srednia[i];
            najlepszaPozycja = i;
        }
    }
    printf("Najlepsza średnia: [%s] %s - %3.2f \n",
    kod_przed[najlepszaPozycja], nazwa_przed[najlepszaPozycja], srednia[najlepszaPozycja]);
}

void najtrudniejszyPrzedmiot(student dane[100], int ile_rekordow)
{
    char kod_przed[100][10];
    char nazwa_przed[100][255];
    int ilePrzedmiotow;
    float srednia[100];
    for(int j = 0; j<100; j++)
        srednia[j]=0;
    int ileDodawan[100];
    for(int j = 0; j<100; j++)
        ileDodawan[j]=0;
    int i;
    int pozycja;
    int najlepszaPozycja;
    float najlepsza = 6.0f;

    ilePrzedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);
    for (i=0; i < ile_rekordow; i++)
    {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ilePrzedmiotow );
        strcpy(nazwa_przed[pozycja], dane[i].nazwa_przed);
        srednia[pozycja] += dane[i].ocena;
        ileDodawan[pozycja]++;        
    }

    for (i=0; i < ilePrzedmiotow; i++)
    {
        srednia[i] = srednia[i] / ileDodawan[i];
    }   

    for (i=0; i < ilePrzedmiotow; i++)
    {
        if (najlepsza > srednia[i])
        {
            najlepsza = srednia[i];
            najlepszaPozycja = i;
        }
    }
    printf("Najgorsza średnia: [%s] %s - %3.2f \n",
    kod_przed[najlepszaPozycja], nazwa_przed[najlepszaPozycja], srednia[najlepszaPozycja]);
}

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    for(int j = 0; j<100; j++){
        sumy_wazonych_ocen[j]=0;
        sumy_ects[j]=0;
}

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }
    
    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}
