#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"



int main(){
    struct Wektor pionek_r[2] = {{0,1},{0,2}}; 
    struct Figura pionek [2] = {{"P", 1, 1, pionek_r},{"P", 2, 1, pionek_r}};
    struct Figura empty = {" "};
    struct Kolor biale;
    biale.pion[0] = &pionek[0];

    
    
int i, j, k;
    int **szachownica =(int**)malloc(8*sizeof(int*)); 
    for(k=0; k<8; k++)
        szachownica[k]=(int*)malloc(8*sizeof(int));
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        szachownica[j][i]=empty.symbol[0];
    }
    
}
    

wstaw (szachownica, pionek[0]);
wstaw (szachownica, pionek[1]);
wyswietl(szachownica);
przesun(szachownica, &pionek[0], pionek[0].ruch[0]);
przesun(szachownica, &pionek[1], pionek[1].ruch[1]);
wyswietl(szachownica);
file_send(szachownica);
   
free(szachownica);



    return 0;
}