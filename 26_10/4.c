#include <stdio.h>

#define dim 3

void input_matrix(int matrix[][dim], int);
void print_matrix(int matrix[][dim], int);

int main()
{
    int matrix[dim][dim];

    input_matrix(&matrix, dim);
    print_matrix(&matrix, dim);
    
    return 0;
}

void input_matrix(int matrix[][dim], int max)
{
    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            printf ("insert value:\n");
            scanf ("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[][dim], int max)
{
    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            printf ("%4d ", matrix[i][j]*2);
        }
        printf ("\n");
    }
}

