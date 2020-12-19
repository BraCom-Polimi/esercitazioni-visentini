#include <stdio.h>
#include <stdlib.h>

double conversione(int x);

int main()
{
    double F;
    printf ("inserire gradi in F:\n");
    scanf ("%lf", &F);
    printf ("i gardi in C sono: %.3lf", (F=conversione(F)));
    return 0;
}

double conversione(int x)
{
    double C;
    C=((x-32)*5)/9;
    return C;
}