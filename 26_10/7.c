#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 3

void input(int matrix[][dim], int);
void print_result(int matrix[][dim], int);

int main ()
{
    srand (time(NULL));

    int matrix[dim][dim];
    input(matrix, dim);
    printf("\n\n");
    print_result(matrix, dim);

    return 0;
}

void input(int matrix [][dim], int max)
{
    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            matrix[i][j]=rand()%10;
            printf ("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_result(int matrix[][dim], int max)
{
    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            printf ("%2d ", matrix[i][j]);
        }
        for (int k=max-1; k>=0; k--)
        {
            printf ("%2d ", matrix[i][k]);
        }
        printf("\n");
    }

    for (int i=max-1; i>=0; i--)
    {
        for (int j=0; j<max; j++)
        {
            printf ("%2d ", matrix[i][j]);
        }
        for (int k=max-1; k>=0; k--)
        {
            printf ("%2d ", matrix[i][k]);
        }
        printf("\n");
    }
}
