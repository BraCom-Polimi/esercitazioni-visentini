#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genera(int A[][2], int *, int *);
void stampa(int A[][2], int *, int *);

int main()
{
    srand(time(NULL));
    int matrix[2][2];
    int det=0, somma=0;
    int *pdet, *psomma;
    pdet=&det;
    psomma=&somma;

    genera(matrix, pdet, psomma);
    stampa(matrix, pdet, psomma);
}

void genera(int A[][2], int *det, int *somma)
{
    for (int i=0; i<2; i++)
    {
        for (int k=0; k<2; k++)
        {
            *(*(A+i)+k)=rand()%10+1;
            *somma+=A[i][k];
        }
    }

    *det=(A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
}

void stampa(int A[][2], int *det, int *somma)
{
    for (int i=0; i<2; i++)
    {
        for (int k=0; k<2; k++)
        {
            printf ("%d ", *(*(A+i)+k));
        }
        printf ("\n");
    }
    printf ("Det: %d\nSomma: %d\n", *det, *somma);
}
