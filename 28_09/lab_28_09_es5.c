#include <stdio.h>
#include <limits.h>

int main ()
{
    printf ("int: %lu\nlong int: %lu\nfloat: %lu\ndouble: %lu\nlong double: %lu\n", sizeof(int), sizeof(long int), sizeof(float), sizeof(double), sizeof(long double));
    return 0;
}
