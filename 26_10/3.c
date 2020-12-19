#include <stdio.h>

#define dim1 5
#define dim2 4

void input_v(int *, int);
void print_v(int *, int);
void equi(int *, int *, int, int);

int main ()
{
    int v1[dim1]={0}, v2[dim2]={0};
    int *p1=v1;
    int *p2=v2;
    input_v(p1, dim1);
    input_v(p2, dim2);
    printf("vettore 1:\n");
    print_v(p1, dim1);
    printf("\n");
    printf("vettore 2:\n");
    print_v(p2, dim1);
    equi(p1, p2, dim1, dim2);

    return 0;
}

void input_v(int *p, int max)
{
    int value;
    int flag=0;

    for (int i=0; i<max; i++)
    {
        printf ("inserisci valore vettore, tutti diversi:\n");
        scanf ("%d", &p[i]);
    }
}

void print_v(int *p, int max)
{
    for (int i=0; i<max; i++)
    {
        printf ("%d ", p[i]);
    }
}

void equi(int *p1, int *p2, int max5, int max4)
{
    printf ("i valori comuni sono:\n")
    for (int i=0; i<max5; i++)
    {
        for (int j=0; j<max4; j++)
        {
            if (p1[i]==p2[j])
                printf ("%d ", p1[i]);
        }
    }
}