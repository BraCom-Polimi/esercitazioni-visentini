#include <stdio.h>

int main ()
{
    int numpiccolo, numgrande, numX, tentativi, indovinato=0, media, contatore=0;

    do
    {
        printf ("inserisci il valore piccolo:\n");
        scanf ("%d", &numpiccolo);
        printf ("inserisci il valore grande:\n");
        scanf ("%d", &numgrande);
        printf ("numero da indovinare:?\n");
        scanf ("%d", &numX);
    } while (numpiccolo>=numgrande || (numX<numpiccolo || numX>numgrande));

    printf ("quanti tentativi vuoi fare?\n");
    scanf ("%d", &tentativi);

    while (indovinato==0 && contatore<tentativi)
    {
        contatore++; 

        media=(numgrande+numpiccolo)/2;
        if (numX==media)
            indovinato=1;
        else if (numX<media)
        {
            numgrande=media;
            media=(numgrande+numpiccolo)/2;

            if (numX==media)
                indovinato=1;
            else
                printf ("%i errato!\n", media);
        }
        else if (numX>media)
        {
            numpiccolo=media;
            media=(numgrande+numpiccolo)/2;

            if (numX==media)
                indovinato=1;
            else
                printf ("%i errato!\n", media);
        }
    }

    if (indovinato==1)
        printf ("trovato! era %d\n", numX);

    else
        printf ("Non l'ho trovato!\n");

    return 0;
}