#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"


void new_szachownica (int **sz, struct Figura empty){
    int i, j, k;
    int **szachownica =(int**)malloc(8*sizeof(int*)); // alokacja pamięci dla wierszy
    for(k=0; k<8; k++)
        szachownica[k]=(int*)malloc(8*sizeof(int));
        
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        szachownica[j][i]=empty.symbol[0];
    }
    
}
}

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
        szachownica[j][i]=*" ";
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
        printf("|");
    for(j=0; j<8; j++){
        
        printf("%c", szachownica[j][i]);
        printf("|");
    }
    printf("\n");
}
}
