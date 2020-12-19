#include <stdio.h>

#define dim 5

int main()
{
    int vector[dim]={0};
    int n=0;
    int value=0;

    while (n<5)
    {
        printf ("il vettore contiene %d elementi. numero per la cella %d?\n", n, n);
        scanf ("%d", &vector[n]);
        value=vector[n];
        if (value==0)
        {
            value=n;
            n=5;
        }
        else
            n++;
    }

    if (n==5)
    {
        printf ( "il vettore contiene %d elementi. il vettore è pieno\nIl vettore con %d elementi:\n", value, value);
    }

    for (int i=0; i<value; i++)
        printf ("%d ", vector[i]);
    
    printf ("\n");
    return 0;
}