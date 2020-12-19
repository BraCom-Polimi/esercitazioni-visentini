#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define str 20

int gg_mese[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct s_data {
    int anno;
    int giorno;
    int mese;
};

struct s_bolletino {
    struct s_data data;
    char meteo[str];
    int cap;
};

int anno_bisestile(int anno);
int verifica_data(struct s_data data, int);
int giorni_da_capodanno(struct s_data data);
void ins_bolletino(struct s_bolletino *p);
void stampa_bolletino(struct s_bolletino *p);

int main()
{
    struct s_bolletino BOLLETTA;
    struct s_bolletino *p=&BOLLETTA;
    ins_bolletino(p);
    return 0;
}

int anno_bisestile(int anno)
{
    if (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0))
        return 1;
    else
        return 0;
    
}
int verifica_data(struct s_data data, int bisestile)
{
    int cond=0;

    if ((data.anno > 2000) && (data.mese >= 1) && (data.mese <= 12))
    {
        if (bisestile == 1)
        {
            if (data.mese == 2)
            {
                if (data.giorno <= gg_mese[2]+1)
                {
                    cond=1;
                }
            }
            else if ((data.mese == 1) || (data.mese == 3) || (data.mese == 5) || (data.mese == 7) || (data.mese == 8) || (data.mese == 10) || (data.mese == 12))
            {
                if (data.giorno <= gg_mese[1])
                {
                    cond=1;
                }
            }
            else
            {
                if (data.giorno <= gg_mese[4])
                {
                    cond=1;
                }
            }
            
        }
        else
        {
            if (data.mese == 2)
            {
                if (data.giorno <= gg_mese[2])
                {
                    cond=1;
                }
            }
            else if ((data.mese == 1) || (data.mese == 3) || (data.mese == 5) || (data.mese == 7) || (data.mese == 8) || (data.mese == 10) || (data.mese == 12))
            {
                if (data.giorno <= gg_mese[1])
                {
                    cond=1;
                }
            }
            else
            {
                if (data.giorno <= gg_mese[4])
                {
                    cond=1;
                }
            }
        }
    }
    else
        cond=0;
    
    return cond;
}
int giorni_da_capodanno(struct s_data data)
{
    int i=1, count=0;

    while (i < data.mese)
    {
        count+=gg_mese[i];
        i++;
    }
    count+=data.giorno;

    return count;
}
void ins_bolletino(struct s_bolletino *p)
{
    struct s_data DATA;
    int bisestile, verifica, gg_da_cap;
    char meteo[str];

    printf ("inserire anno:\n");
    scanf ("%d", &DATA.anno);
    printf ("inserire mese:\n");
    scanf ("%d", &DATA.mese);
    printf ("inserire giorno:\n");
    scanf ("%d", &DATA.giorno);

    bisestile=anno_bisestile(DATA.anno);
    verifica=verifica_data(DATA, bisestile);
    
    if (verifica == 1)
    {
        p->data.anno=DATA.anno;
        p->data.mese=DATA.mese;
        p->data.giorno=DATA.giorno;
        printf ("data inserita e' corretta\n");

        printf ("inserire meteo: \n");
        scanf ("%s", meteo);
        strcpy (p->meteo, meteo);

        gg_da_cap=giorni_da_capodanno(DATA);
        if (bisestile == 1)
            gg_da_cap++;
        p->cap=gg_da_cap;

        stampa_bolletino(p);
    }
    else
    {
        printf ("data inserita non corretta\n");
    }
    
}
void stampa_bolletino(struct s_bolletino *p)
{
    printf ("Anno: %d\nMese: %d\nGiorno: %d\nMeteo: %s\nGiorni da cap: %d\n", p->data.anno, p->data.mese, p->data.giorno, p->meteo, p->cap);
}
