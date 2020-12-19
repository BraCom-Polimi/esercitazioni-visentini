#include <stdio.h>

int ask();
void words(int n);
void calculate(int n);

int main()
{
    int num=ask();
    calculate(num);
    printf ("\n");

    return 0;
}

int ask()
{
    int n;

    do
    {
        printf ("insert a positive number:\n");
        scanf ("%d", &n);

        if (n<0)
            printf ("the num is negatuve!\n");
    } while (n<0);

    return n;
}

void words(int n)
{
    switch (n)
    {
        case 0:
            printf("zero ");
        break;

        case 1:
            printf ("uno ");
        break;

        case 2:
            printf ("due ");
        break;

        case 3:
            printf ("tre ");
        break;

        case 4:
            printf ("quattro ");
        break;

        case 5:
            printf ("cinque ");
        break;

        case 6:
            printf ("sei ");
        break;

        case 7:
            printf ("sette ");
        break;

        case 8:
            printf ("otto ");
        break;

        case 9:
            printf ("nove ");
        break;
    }
}

void calculate(int num)
{
    if ((num/10)==0)
        words(num%10);
    else if ((num/10)!=0)
    {
        calculate(num/10);
        words(num%10);
    }  
}