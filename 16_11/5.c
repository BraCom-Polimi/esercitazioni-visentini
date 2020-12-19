#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 10

typedef float t_matrice[dim][dim];

void calcola(t_matrice M, int O[dim][dim]);
//controllo 'dentro' all'intenro di media
float media(int O[dim][dim], int i, int j);
void fill(int O[][dim]);

int main()
{
    srand(time(NULL));
    int A[dim][dim];
    t_matrice B;
    fill(A);
    calcola(B, A);

    printf ("matrix originale:\n");
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            printf ("%.2d ", A[i][j]);
        }
        printf ("\n");
    }
    printf ("matrix medie:\n");
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            printf ("%.2lf ", B[i][j]);
        }
        printf ("\n");
    }
    return 0;
}

void fill(int O[][dim])
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            O[i][j]=rand()%10+1;
        }
    }
}

void calcola(t_matrice M, int O[dim][dim])
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            M[i][j]=media(O, i, j);
        }
    }
}
float media(int O[dim][dim], int i, int j)
{
    float sum=0, counter=0;

    if (i-1 >= 0 && j-1 >= 0)
    {
        sum+=O[i-1][j-1];
        counter++;
    }
    if (i+1 < dim && j+1 < dim)
    {
        sum+=O[i+1][j+1];
        counter++;
    }
    if (i-1 >= 0)
    {
        sum+=O[i-1][j];
        counter++;
    }
    if (i-1 >= 0 && j+1 < dim)
    {
        sum+=O[i-1][j+1];
        counter++;
    }
    if (i+1 < dim && j-1 >= 0)
    {
        sum+=O[i+1][j-1];
        counter++;
    }
    if (j-1 >= 0)
    {
        sum+=O[i][j-1];
        counter++;
    }
    if (j+1 < dim)
    {
        sum+=O[i][j+1];
        counter++;
    }
    if (i+1 < dim)
    {
        sum+=O[i+1][j];
        counter++;
    }

    sum/=counter;
    return sum;
}

 