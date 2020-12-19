#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define dim 10

struct node{
    int val;
    char letter;
    struct node *next;
};

struct node *createE(char letter, int val);
void printL(struct node *L);
void insertH(struct node **L, struct node *I);
void insertT(struct node **L, struct node *I);
void freeList(struct node *L);
struct node *findE(struct node *L, char letter);
struct node *group(struct node *L);
void deleteNode(struct node **L, int val);
void separeL(struct node **L, struct node **even, struct node **odd);
int evenOdd(struct node *N);
int saveList(struct node *L1, struct node *L2);
int loadList(struct node **L);

int main(){
    srand(time(NULL));
    int error;
    struct node *List1 = NULL;
    struct node *List2 = NULL;
    struct node *List3 = NULL;
    struct node *List4 = NULL;
    struct node *even = NULL;
    struct node *odd = NULL;
    struct node *T = NULL;
    int i = 0, n;
    char l;
    //head insert
    while (i < dim){
        n = rand()%10;
        l = 'A' + rand()%('Z'-'A'+1);
        T = createE(l, n);
        insertH(&List1, T);
        
        i++;
    }
    printL(List1);

    printf ("\n\n");

    //tail insert
    i = 0;
    while (i < dim){
        n = rand()%10;
        l = 'A' + rand()%('Z'-'A'+1);
        T = createE(l, n);
        insertT(&List2, T);
        
        i++;
    }
    printL(List2);

    //find element
    printf ("\ninsert letter to search: (UPPERCASE)\n");
    scanf (" %c", &l);
    T = findE(List1, l);
    if (T == NULL)
        printf ("nope\n");
    else
        printf ("%c - %d\n", T->letter, T->val);

    //group
    List3 = group(List1);
    printL(List3);

    //delete node
    printf ("\ninsert the code to delete from List1:\n");
    scanf ("%d", &n);
    deleteNode(&List1, n);
    printf ("list after deletion:\n");
    printL(List1);
    printf ("\n\n");

    
    //separe
    separeL(&List2, &even, &odd);
    //printL(List2);
    printf ("\n");
    printL(even);
    printf ("\n");
    printL(odd);

    //file
    printf ("save: %d\n", (error = saveList(List1, List2)));
    printf ("load: %d\n", (error = loadList(&List4)));
    printL(List4);

    freeList(List1);
    //do not free list 2 ;)
    freeList(List3);
    freeList(List4);
    freeList(even);
    freeList(odd);
    return 0;
}

struct node *createE(char letter, int val){
    struct node *N = (struct node*)malloc(sizeof(struct node));
    if (N != NULL){
        N->letter = letter;
        N->val = val;
        N->next = NULL;
    }
    return N;
}

void printL(struct node *L){
    struct node *curr = L;
    if (curr != NULL){
        while (curr != NULL){
            printf ("%c - %d  ", curr->letter, curr->val);
            curr = curr->next;
        }
    }
}

void insertH(struct node **L, struct node *I){
    struct node *curr = *L;

    if (*L == NULL){
        *L = I;
    }
    else{
        I->next = curr;
        *L = I;
    }
}

void insertT(struct node **L, struct node *I){
    struct node *curr = *L;
    struct node *t = *L;

    if (curr == NULL)
        *L = I;
    else{
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = I;
    }
}

void freeList(struct node *L){
    struct node *curr = L;
    struct node *prev = NULL;

    if (L == NULL)
        return;
    
    while (curr != NULL){
        if (prev != NULL)
            free(prev);
        prev = curr;
        curr = curr->next;
    }
    free(prev);
}

struct node *findE(struct node *L, char letter){
    struct node *curr = L;

    if (curr == NULL)
        return NULL;
    while (curr != NULL){
        if (curr->letter == letter)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

struct node *group(struct node *L){
    char l;
    struct node *newList = NULL;
    struct node *test = NULL;
    struct node *currL = L;
    if (currL == NULL){
        return NULL;
    }

    while (currL != NULL){
        l = currL->letter;
        test = findE(newList, l);
        if (test == NULL){
            test = createE(l, currL->val);
            insertT(&newList, test);
        }
        else{
            test->val += currL->val;
        }
        currL = currL->next;
    }
    return newList;
}

void deleteNode(struct node **L, int val){
    struct node *curr = *L;
    struct node *prev = NULL;

    if (curr == NULL){
        printf ("empty\n");
    }
    while (curr != NULL){
        if (curr == *L && curr->val == val){
            *L = curr->next;
            free(curr);
            curr = *L;
        }
        else if (curr->next == NULL && curr->val == val){
            free(curr);
        }
        else if (curr->val == val){
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        prev = curr;
        curr = curr->next;
    }
}

int evenOdd(struct node *N){
    if (N->val%2 == 0 || N->val == 0)
        return 1;
    else
        return 0;
}

void separeL(struct node **L, struct node **even, struct node **odd){
    struct node *curr = *L;
    struct node *evenCurr = NULL;
    struct node *oddCurr = NULL;
    bool evenF = false, oddF = false;

    if (*L == NULL){
        printf ("empty\n");
        return;
    }
    deleteNode(L, 5);
    while (curr != NULL){
        if (evenOdd(curr) == 1){
            if (evenF == false){
                *even = curr;
                evenF = true; 
                evenCurr = *even;
            }
            else{
                evenCurr->next = curr;
                evenCurr = evenCurr->next;
            }
        }
        else{
            if (oddF == false){
                *odd = curr;
                oddF = true;
                oddCurr = *odd;
            }
            else{
                oddCurr->next = curr;
                oddCurr = oddCurr->next;
            }
        }
        curr = curr->next;
    }
    oddCurr->next = NULL;
    evenCurr->next = NULL;
    *L = NULL;
}

//argc argv no sbatti pls
int saveList(struct node *List1, struct node *List2){
    bool fl = false;
    FILE *f = fopen("list.txt", "w");
    struct node *curr = List1;
    if (curr == NULL){
        printf ("empty\n");
        fl = true;
    }
    else{
        while (curr != NULL){
            fprintf(f, "%c %d\n", curr->letter, curr->val);
            curr = curr->next;
        }
    }
    fclose(f);

    f = fopen("list_bin.bin", "w");
    curr = List2;
    if (curr == NULL){
        printf("empty\n");
        fl = true;
    }
    else{
        while (curr != NULL){
            fwrite(curr, sizeof(struct node), 1, f);
            curr = curr->next;
        }
    }
    fclose(f);

    if (fl == true)
        return -1;
    else
        return 0;
}
//ex to load a list form a file
int loadList(struct node **L){
   struct node *curr = *L;
   struct node *t = NULL;
    char l;
    int n, i;
    char s[10];
    FILE *f = fopen("list.txt", "r");
    if (*L != NULL)
        return -1;
    
    fgets(s, 10, f);
    while (feof(f) != 1){
        i = 0;
        while (i < strlen(s)){
            if (s[i] >= 65 && s[i] <= 90){
                l = s[i];
            }
            else if (s[i] != ' ' && s[i] >= 48 && s[i] <= 57){
                n = atoi(&s[i]);
            }
            i++;
        }
        t = createE(l, n);
        insertT(L, t);
        fgets(s, 10, f);
    }
    fclose(f);

    return 0;
}


