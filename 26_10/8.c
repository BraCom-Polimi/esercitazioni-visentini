#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 9

bool verify_row(int s[][max]);
bool verify_col(int s[][max]);
bool verify_squ(int s[][max]);
void sort_row(int s[max][max]);
void sort_col(int s[max][max]);
void print(int s[][max]);
void fill(int sudoku[][max], int tofill[][max]);
bool fill_small(int *p, int s[][max], int, int);
void print_small(int *p);
void sort_small(int *p);
bool check_small(int *p);

int main()
{
    bool flag=true;
    int count=0;
    int sudoku [max][max]={
     {1,2,3,4,5,6,7,8,9},
     {4,5,6,7,8,9,1,2,3},
     {7,8,9,1,2,3,4,5,6},
     {2,3,4,5,6,7,8,9,1},
     {5,6,7,8,9,1,2,3,4},
     {8,9,1,2,3,4,5,6,7},
     {3,4,5,6,7,8,9,1,2},
     {6,7,8,9,1,2,3,4,5},
     {9,1,2,3,4,5,6,9,8}
    };
    int s2[max][max];

    //I sort the row so the check is easly
    fill(sudoku, s2);
    sort_row(s2);
    print(s2);

    if (verify_row(s2)==true)
    {
        printf ("row correct!\n");
        
        fill(sudoku, s2);
        sort_col(s2);
        print(s2);
        if (verify_col(s2)==true)
        {
            printf ("columns correct!\n");

            fill(sudoku, s2);
            if (verify_squ(s2)==true)
                printf ("sudoku correct!\n");
            else
                printf ("small squares not correct!\n");
        }
        else
            printf ("columns not correct!\n"); 
    }
    else
        printf ("rows not correct!\n");

    return 0;
}

void fill(int sudoku[][max], int tofill[][max])
{
    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            tofill[i][j]=sudoku[i][j];
        }
    }
}

void print(int s[][max])
{
    int i, j;

    for (i=0; i<max; i++)
    {
        for (j=0; j<max; j++)
        {
            printf ("%d, ", s[i][j]);
        }
        printf ("\n");
    }
}

void sort_row(int s[max][max])
{
    int tmp;

    //bubble sort
     for (int i=0; i<max; i++)
     {
         for (int j=0; j<max-1; j++)
         {
             for (int k=0; k<max-1; k++)
             {
                if (s[i][k]>=s[i][k+1])
                {
                    tmp=s[i][k];
                    s[i][k]=s[i][k+1];
                    s[i][k+1]=tmp;
                }                
             }
         }
     }
}

void sort_col(int s[][max])
{
    int tmp;

    //bubble sort
     for (int i=0; i<max; i++)
     {
         for (int j=0; j<max-1; j++)
         {
             for (int k=0; k<max-1; k++)
             {
                if (s[k][i]>=s[k+1][i])
                {
                    tmp=s[k][i];
                    s[k][i]=s[k+1][i];
                    s[k+1][i]=tmp;
                }                
             }
         }
     }
}

bool verify_row(int s[][max])
{
    bool result=true;
    int counter=0, c1=0;

    while (result==true && counter<max)
    {
        while (c1<max && result==true)
        {
            if (s[counter][c1]==(c1+1))
                result=true;
            else
                result=false;
            c1++;
        }
        counter++;
    }

    return result;
}

bool verify_col(int s[][max])
{
    bool result=true;
    int c=0, c1=0;
    
    while (result==true && c<max)
    {
        while (c1<max && result==true)
        {
            if (s[c1][c]==c1+1)
                result=true;
            else
                result=false;
            c1++;
        }
        c++;
    }

    return result;
}

bool verify_squ(int s[][max])
{
    int a[max]={0};
    int *p=a;
    int c=0, c1=0;
    bool flag=true;
    
    while (flag==true && c<max)
    {
        c1=0;
        while (c1<max && flag==true)
        {
            if (fill_small(p, s, c, c1)==true)
                flag=true;
            else
                flag=false;
            c1+=3;
        }
        c+=3;
    }
    
    return flag;
}

bool fill_small(int *p, int s[][max], int dim1, int dim2)
{
    bool result=false;
    //strange names but they are only the two for cicle counters
    int counter_p, counter_p_i;

    for (int i=dim1, counter_p=0; i<dim1+3; i++, counter_p+=3)
    {
        for (int j=dim2, counter_p_i=counter_p; j<dim2+3; j++, counter_p_i++)
        {
            *(p+counter_p_i)=s[i][j];
        }
    }
    sort_small(p);
    print_small(p);

    return result=check_small(p);
}

void sort_small(int *p)
{
    int tmp;

    for (int i=0; i<max; i++)
    {
        for (int j=0; j<max; j++)
        {
            if (*(p+j)>=*(p+j+1))
            {
                tmp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=tmp;
            }
        }
    }
}

bool check_small(int *p)
{
    bool result=true;
    int c=0;

    while (result==true && c<max)
    {
        if (*(p+c)==c+1)
            result=true;
        else
            result=false;
        c++;
    }

    return result;
}

void print_small(int *p)
{
    for (int i=0; i<max; i++)
        printf ("%d, ", *(p+i));
    printf ("\n");
}