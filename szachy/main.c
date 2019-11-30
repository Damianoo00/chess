#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"



int main(){
    struct Figura pionek [3] = {{"P", 1, 1},{"P", 2, 2},{"P", 1, 3}};
    struct Figura empty = {" "};
    
int i, j, k;
    int **szachownica =(int**)malloc(8*sizeof(int*)); // alokacja pamięci dla wierszy
    for(k=0; k<8; k++)
        szachownica[k]=(int*)malloc(8*sizeof(int));
        
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        szachownica[j][i]=empty.symbol[0];
    }
    
}
    
    
wstaw (szachownica, pionek[0]);
wstaw (szachownica, pionek[1]);
wstaw (szachownica, pionek[2]);
przesun(szachownica, &pionek, 7, 7);
wyswietl(szachownica);
   




    return 0;
}