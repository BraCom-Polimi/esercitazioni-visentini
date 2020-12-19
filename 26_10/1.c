#include <stdio.h>

#define dim 10

int main()
{
    int c, r;

    for (c=1; c<=dim; c++)
    {
        printf ("%4d ", c);
    }
    printf ("\n");
    for (r=1; r<=dim; r++)
    {
        if (r==10)
            printf ("%d|", r);
        else if (r!=10)
            printf ("%2d", r);
        for (c=1; c<=dim; c++)
        {
            if (((c*r)%5==0) && ((c*r)%7==0))
                printf ("%3d*", c*r);
            else 
                printf ("%4d", c*r);
        }
        printf ("\n");
    }

    return 0;
}