#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"


void wstaw(int **szachownica, struct Figura f){
    int i, j;
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        if (i==f.y-1 && j==f.x-1)
        szachownica[j][i]=f.symbol[0];
    }
    
}
}

void usun(int **szachownica, struct Figura f){
    int i, j;
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        if (i==f.y-1 && j==f.x-1)
        szachownica[j][i]=NULL;
    }
    
}
}
void przesun(int **szachownica, struct Figura *f, int x, int y){
    usun(szachownica, *f);
    f->x+=x;
    f->y+=y;
    wstaw(szachownica, *f);
}

void wyswietl(int **szachownica){
    int i, j;
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        printf("%d ", szachownica[j][i]);
    }
    printf("\n");
}
}
