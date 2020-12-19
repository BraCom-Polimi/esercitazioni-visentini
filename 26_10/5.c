#include <stdio.h>
#include <string.h>

void input_name(char *);
void print_hello(char *);

int main()
{
    char name[10];
    char *p=name;

    input_name(p);
    print_hello(p);

    return 0;
}

void input_name(char *p)
{
    printf ("insert a name (max 9 charaters)\n");
    scanf ("%s", p);
}

void print_hello(char *p)
{
    int lenght=strlen(p);

    printf ("Hello %s!\nthe lenght of your name is:\n%d\n", p, lenght);
}
