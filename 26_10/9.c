#include <stdio.h>
#include <string.h>

struct book {
    char name[20];
    char gender;
    int age;
};

void input(struct book *p);
void result(struct book *p);
struct book min_female_start(struct book *p);
struct book min_male_start(struct book *p);
struct book min_female_finish(struct book *p);
struct book min_male_finish(struct book *p);
struct book male_over_25(struct book *p, int);

int main()
{
    struct book total[5];
    struct book *p=total;

    input(p);
    result(p);

    return 0;
}

void input(struct book *p)
{
    struct book temp;

    for (int i=0; i<5; i++)
    {
        printf ("insert name:\n");
        scanf ("%s", temp.name);
        strcpy(p[i].name, temp.name);
        printf ("insert gender:\n");
        scanf (" %c", &temp.gender);
        p[i].gender=temp.gender;
        printf ("insert age:\n");
        scanf ("%d", &temp.age);
        p[i].age=temp.age;
    }
}

void result(struct book *p)
{
    struct book final[6];
    int position=0;

    //final[0]
    printf ("youngest male:\n");
    final[0].age=(min_male_finish(p)).age;
    printf ("age: %d\n", final[0].age);
    strcpy(final[0].name, (min_male_finish(p)).name);
    printf ("name: %s\n", final[0].name);
    final[0].gender=(min_male_finish(p)).gender;
    printf ("gender: %c\n", final[0].gender);
    printf ("\n\n");
    //final [1]
    printf ("youngest female:\n");
    final[1].age=(min_female_finish(p)).age;
    printf ("age: %d\n", final[1].age);
    strcpy(final[1].name, (min_female_finish(p)).name);
    printf ("name: %s\n", final[1].name);
    final[1].gender=(min_female_finish(p)).gender;
    printf ("gender: %c\n", final[1].gender);
    printf ("\n\n");
    //final [2] and beyond
    for (int i=2; i<6; i++)
    {
        if ((male_over_25(p, position).age)!=0) //stampo solo se la funzione ritorna un age diverso da zero, cioè ha trovato un contatto con età maggiore a 25
        {
            printf ("male over 25 years old:\n");
            final[i].age=(male_over_25(p, position)).age;
            printf ("age: %d\n", final[i].age);
            strcpy(final[i].name, (male_over_25(p, position)).name);
            printf ("name: %s\n", final[i].name);
            final[i].gender=(male_over_25(p, position)).gender;
            printf ("gender: %c\n", final[i].gender);
            printf ("\n\n");

            position++;
        }
    }    
}

struct book min_female_start(struct book *p)
{
    struct book FF; //for the minimun female age

    for (int i=0; i<5; i++)
    {
        if (p[i].gender=='f')
        {
             FF.age=p[i].age;
             i=5;
        }
    }
    
    return FF;
}

struct book min_male_start(struct book *p)
{
    struct book MM; //for the minìmun male age
    
    for (int i=0; i<5; i++)
    {
        if (p[i].gender=='m')
        {
             MM.age=p[i].age;
             i=5;
        }
    }

    return MM;
}

struct book min_female_finish(struct book *p)
{
    struct book FF;
    
    for (int i=0; i<5; i++)
    {
        if (((p[i].age)<=min_female_start(p).age) && ((p[i].gender)=='f'))
        {
            FF.age=p[i].age;
            strcpy(FF.name, p[i].name);
            FF.gender=p[i].gender;
        }
    }

    return FF;
}

struct book min_male_finish(struct book *p)
{
    struct book MM;

    for (int i=0; i<5; i++)
    {
        if (((p[i].age)<=min_male_start(p).age) && ((p[i].gender)=='m'))
        {
            MM.age=p[i].age;
            strcpy(MM.name, p[i].name);
            MM.gender=p[i].gender;
        }
    }

    return MM;
}

struct book male_over_25(struct book *p, int position)
{
    struct book O25;
    int counter=0, i=position;
    O25.age=0;

    while (counter==0 && i<5)
    {
        if ((p[i].age)>25 && p[i].gender=='m')
        {
            O25.age=p[i].age;
            strcpy(O25.name, p[i].name);
            O25.gender=p[i].gender;
            counter++;
        }
        i++;
    }

    return O25;
}
