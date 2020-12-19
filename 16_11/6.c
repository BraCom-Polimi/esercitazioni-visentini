#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define max 10

static int C=0;

struct node {
    int val;
    struct node *next;
};

struct start {
    struct node *head;
};

void enqueue(struct start *H, int value);
void dequeue(struct start *H);
struct start *newlist();
void printlist(struct start *H);
void freelist(struct start *H);

int main()
{
    srand (time(NULL));
    struct start *H=newlist();
    int counter=0, game, n;

    while (counter <= 15)
    {
        game=rand()%2;
        n=rand()%10+1;
        if (game == 1 && C < 10)
        {
            enqueue(H, n);
            printf ("Passo %d di 15. INGRESSO %d. Coda: ", counter, n);
            printlist(H);
            printf ("\n");
        }
        else if (game == 1 && C >= 10)
            printf ("Passo %d di 15. INGRESSO di %d NON RIUSCITO. Coda Piena!\n", counter, n);
        else if (game == 0 && C > 0)
        {
            printf ("Passo %d di 15. USCITA. Coda: ", counter);
            dequeue(H);
            printlist(H);
            printf ("\n");
        }
        else if (game == 0 && C == 0)
            printf ("Passo %d di 15. USCITA NON RIUSCITA. Coda Vuota!\n", counter);
        counter++;
    }
    free(H);
    return 0;
}
//this function is a insert on tail (list)
void enqueue(struct start *H, int value)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *curr=H->head;
    newnode->val=value;

    if (H->head == NULL)
    {
        H->head=newnode;
        newnode->next=NULL;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr=curr->next;
        }
        curr->next=newnode;
        newnode->next=NULL;
    }
    C++;
}
//remove the tail
void dequeue(struct start *H)
{
    C--;
    struct node *curr=H->head;
    struct node *tofree=NULL;
    if (curr->next == NULL)
    {
        H->head=NULL;
        return;
    }
    else
    {
        while (curr->next != NULL)
        {
            tofree=curr;
            curr=curr->next;
        }
        tofree->next=NULL;
        free(curr);
    }
}
struct start *newlist()
{
    struct start *head=(struct start *)malloc(sizeof(struct start));
    head->head=NULL;
    return head;
}

void printlist(struct start *H)
{
    struct node *curr=H->head;

    while (curr != NULL)
    {
        printf ("%d ", curr->val);
        curr=curr->next;
    }
}
void freelist(struct start *H)
{
    struct node *current=H->head;
    struct node *previous=NULL;

    while (current!=NULL)
    {
        if (previous!=NULL)
        {
            free(previous);
        }
        previous=current;
        current=current->next;
    }
    //this if is needed because al the last element of the list, previous is = current, but current is current is -> next so it's = NULL. 
    //The last element of the list won't be freed with only the while cicle. we need the if condition below
    if (previous != NULL)
        free(previous); //---> this is the last element of the list
    
    free(H);
}
