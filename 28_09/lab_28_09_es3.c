#include <stdio.h>

int main (){
    int x = 3;
    float y = 3.0;
    float r1, r2, r3;
    r1 = x / 2;
    r2 = x / 2.0;
    r3 = y / 2;
    //r1 sarà 1 float in quanto int tronca la parte decimale ma poi viene assegnata a un float
    /*r2 sarà 1.5 in quanto dividendo un int per un float (2.0), il float converte la parte intera in decimale
    poi viene comunque assegnata ad r2 (float)*/
    //r3 sarà 1.5 per lo stesso motivo
    printf ("%.3f\n%.3f\n%.3f\n", r1, r2, r3); //%.3f assegna tre posti alla parte decimale
    //in notazione scientifica
    printf ("%.2e\n%.2e\n%.2e\n", r1, r2, r3);
    return 0;
}