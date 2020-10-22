#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    float a1, a11;
    a1 = atof(argv[1]);
    a11 = a1*a1;

    printf("Wartość %s do kwadratu to %1.0f\n ", argv[1], a11);

    return 0;
}