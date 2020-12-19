#include <stdio.h>

int main ()
{
    int num, tab=0;
    printf ("inserire un numero intero: \n");
    scanf ("%i", &num);
    printf ("La tabellina del numero %i è:\n", num);
    for (int i=0; i<10; i++)
    {
        tab=tab+num;
        printf ("%i ", tab);
    }
    return 0;
}