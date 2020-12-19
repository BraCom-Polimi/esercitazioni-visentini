#include <stdio.h>

int main ()
{
    int num;
    printf ("inserire un numero:\n");
    scanf ("%i", &num);
    printf ("il resto della divisione tra %i e 2 è: %i\n", num, num%2);
    if (num%2==0)
    {
        printf ("%i è pari!\n", num);
    }
    else 
    {
        printf ("%i è dispari!\n", num);
    }
    return 0;
}