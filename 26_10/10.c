#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 100

void fill(int *);
void count(int *, int *);

int main()
{
    srand(time(NULL));

    int array[dim];
    int result[10];
    int *pA=array;
    int *pR=result;

    fill(pA);
    count(pA, pR);

    return 0;
}

void fill(int *p)
{
    for (int i=0; i<dim; i++)
    {
        p[i]=rand()%100;
    }
}

void count(int *pA, int *pR)
{
    int c[10]={0};
    int division=0;

    for (int i=0; i<100; i++)
    {   
        division=pA[i]/10;

        switch (division)
        {
            case 0:
                c[0]++;
            break;

            case 1:
                c[1]++;
            break;
        
            case 2:
                c[2]++;
            break;

            case 3:
                c[3]++;
            break;

            case 4:
                c[4]++;
            break;

            case 5:
                c[5]++;
            break;

            case 6:
                c[6]++;
            break;

            case 7:
                c[7]++;
            break;

            case 8:
                c[8]++;
            break;

            case 9:
                c[9]++;
            break;
        }
    }
    for (int j=0; j<10; j++)
    {
        printf ("%d ", c[j]);
    }
    printf ("\n");
}



