#include <stdio.h>

int main()
{
    int num, num1=1;

    for (int j=1; j<=199; j++)
    {
        num=j;
        num1=j+1;
        
        if (((num%3==0) || (num%5==0)) && ((num1%3==0) || (num1%5==0)))
            printf ("%i, %i\n", num, num1);
    }

    return 0;
}