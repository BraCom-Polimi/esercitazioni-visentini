#include <stdio.h>

int main (){
    char inome, icognome;
    printf ("Inserisci la iniziale del nome:\n");
    scanf (" %c", &inome);
    printf ("Inserisci la iniziale del cognome:\n");
    scanf (" %c", &icognome);
    printf ("Le iniziali del tuo nome e cognome sono:\n%c.%c.\n", inome, icognome);

    //fatto col getchar e putchar
    char n, m;
    n=getchar();
    m=getchar();
    putchar(n);
    //printf(".");
    putchar(m);
    //printf(".\n");
    return 0;
}