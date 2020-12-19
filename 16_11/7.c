#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//en max 5

#define dim 5
static int C=0;
struct nave {
    int x;
    int y;
    int e;
};

void fill(int A[][dim]);
void fill_nave(struct nave *);
void setup_navi(int A[][dim], struct nave *);
void stampa_matrix(int A[][dim]);
void fuoco(int A[][dim]);

int main()
{
    srand(time(NULL));
    int matrix[dim][dim];
    struct nave array[5];
    struct nave *p=array;
    fill(matrix);
    fill_nave(p);
    printf ("campo:\n");
    stampa_matrix(matrix);
    printf ("Navi posizionate:\n");
    setup_navi(matrix, p);
    stampa_matrix(matrix);
    printf ("\n");
    fuoco(matrix);
    printf ("battaglia finita!\n");
    stampa_matrix(matrix);

    return 0;
}

void fill(int A[][dim])
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            A[i][j]=-1;
        }
    }
}

void fill_nave(struct nave *p)
{
    for (int i=0; i<dim; i++)
    {
        p[i].x=rand()%5;
        p[i].y=rand()%5;
        p[i].e=rand()%5+1; 
    }
}

void stampa_matrix(int A[][dim])
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            printf ("%d ", A[i][j]);
        }
        printf ("\n");
    }
}

//attenzione: se una nave ha le stesse coordinate di una nave che è stata posizionata nelle sue stesse coordinate non verrà conteggiata!
void setup_navi(int A[][dim], struct nave *p)
{
    for (int i=0; i<dim; i++)
    {
        if (A[p[i].x][p[i].y] == -1)
        {
            A[p[i].x][p[i].y]=p[i].e;
            C++;
        }
    }
}

void fuoco(int A[][dim])
{
    int x, y;

    while (C > 0)
    {
        x=rand()%5;
        y=rand()%5;
        if (A[x][y] > 0)
        {
            A[x][y]--;
            if (A[x][y] == 0)
                C--;
        }  
    }
}

