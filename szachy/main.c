#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"



int main(){
      
    int **szachownica =(int**)malloc(8*sizeof(int*)); // alokacja pamięci dla wierszy
    for(int i=0; i<8; i++)
        szachownica[i]=(int*)malloc(8*sizeof(int));
        struct Figura pionek = {"P", 1, 1};
    
wstaw (szachownica, pionek);
przesun(szachownica, &pionek, 7, 7);
wyswietl(szachownica);
   




    return 0;
}