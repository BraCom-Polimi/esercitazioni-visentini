#include <stdio.h>

int main ()
{
    int num, somma=0;
    do
    {
        printf ("Inserire un numero maggiore di zero: \n");
        scanf ("%i", &num);
    }while (num<=0);
    
    for (int i=0; i<num; i++)
    {
        somma=somma+i+1; //+1 perché l'indice del contatore for parte da zero
    }
    printf ("La somma dei primi %i numeri interi è: %i\n", num, somma);
    return 0;
}