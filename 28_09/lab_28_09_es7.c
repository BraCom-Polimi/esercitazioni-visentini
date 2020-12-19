#include <stdio.h>

int main ()
{
    char GiocatoreUno, GiocatoreDue;
    printf("Il giocatore uno inserisca s/c/f: \n");
    scanf (" %c", &GiocatoreUno);
    printf ("Il giocatore due inserisca s/c/f: \n");
    scanf (" %c", &GiocatoreDue);
    if (GiocatoreUno=='s')
    {
        if (GiocatoreDue=='f')
        {
            printf ("Vince uno!\n");
        }
        else if (GiocatoreDue=='c')
        {
            printf ("Vince due!\n");        
        }
        else if (GiocatoreDue=='s')
        {
            printf ("Pari!\n");        
        }
    }
    else if (GiocatoreUno=='c')
    {
        if (GiocatoreDue=='f')
        {
            printf ("Vince due!\n");
        }
        else if (GiocatoreDue=='c')
        {
            printf ("Pari!\n");        
        }
        else if (GiocatoreDue=='s')
        {
            printf ("Vince uno!\n");        
        }
    }
    else if (GiocatoreUno=='f')
    {
        if (GiocatoreDue=='s')
        {
            printf ("Vince due!\n");
        }
        else if (GiocatoreDue=='f')
        {
            printf ("Pari!\n");        
        }
        else if (GiocatoreDue=='c')
        {
            printf ("Vince uno!\n");        
        }
    }
    return 0;

}