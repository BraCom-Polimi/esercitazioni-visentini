#include <stdio.h>

int main (){
    int a, b, somma;
    printf ("inserisci il valore della prima e seconda variabile (enter dopo ogni variabile)\n");
    scanf ("%i", &a);
    scanf ("%i", &b);
    somma = a + b;
    printf ("%i + %i = %i\n", a, b, somma);
    return 0;
}