#ifndef _kalkulacje_h
#define _kalkulacje_h

macierz *suma(macierz *macA, macierz *macB);
macierz *roznica(macierz *macA, macierz *macB);
macierz *wymnozSkalar(macierz *macA, float n);
macierz *wymnozMacierz(macierz *macA, macierz *macB);
float norm(macierz *m);

#endif