#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 50

void estrazione(char *s, char letter, char *r, int l);

int main()
{
    char s[max];
    char r[max];
    char letter;
    int lenght;

    printf ("inserire la stringa:\n");
    scanf ("%s", s);
    printf ("inserire lettera:\n");
    scanf (" %c", &letter);
    lenght=strlen(s);
    s[lenght]='\0';
    estrazione(s, letter, r, lenght);
    printf ("%s\n", r);
    return 0;
}

void estrazione(char *s, char letter, char *r, int l)
{
    int i=0, j=0, k=1, flag=0, flag_s=0;

    while (i < l && flag == 0)
    {
        if (s[i]==letter)
        {
            r[0]=letter;
            j=i+1;
            while (j < l && s[j] != letter && flag == 0)
            {
                r[k]=s[j];
                k++;
                j++;
            }
            if (s[j] == letter)
                flag_s=1;
            flag=1;
        }
        i++;
    }
    if (flag_s != 0)
    {
        r[k]=letter;
        r[k+1]='\0';
    }
    else if (flag_s == 0)
    {
        r[k]='\0';
    }
}