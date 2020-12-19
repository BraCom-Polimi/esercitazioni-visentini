#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 10

void insert(int *p, int);
void sum(int *p1, int *p2, int *p3, int);
void visual(int *, int*, int*, int);

int main ()
{
    srand (time(NULL));

    int v1[max], v2[max], v3[max];
    int value;
    int *p1=v1;
    int *p2=v2;
    int *p3=v3;

    do
    {
        printf ("quanti valori da 1 a 10 vuoi usare?\n");
        scanf ("%d", &value);
            if (value<1 || value>10)
                printf ("non corretto!\n");
    } while (value<1 || value>10);
    

    insert(p1, value);
    insert(p2, value);
    sum(p1, p2, p3, value);
    visual(p1, p2, p3, value);

    return 0;
}

void insert(int *p, int v)
{
    srand (time(NULL));
    for (int i=0; i<v; i++)
    {
        p[i]=rand()%10;
    }
}

void sum(int *p1, int *p2, int *p3, int v)
{
    int first;
    int last;

    for (first=0, last=v-1; first<v; first++, last--)
    {
        p3[first]=(p1[first]+p2[last]);
    }
}

void visual(int *p1, int *p2, int *p3, int v)
{
    for (int i=0; i<v; i++)
    {
        printf ("%2d ", p1[i]);
    }
    printf("\n");
    for (int i=0; i<v; i++)
    {
        printf ("%2d ", p2[i]);
    }
    printf("\n");
    for (int i=0; i<v; i++)
    {
        printf ("%2d ", p3[i]);
    }
    printf("\n");
}



