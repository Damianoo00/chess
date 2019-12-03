#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"



int main(){
    int i, j, k, l;
    struct Wektor pionek_r[2] = {{0,1},{0,2}}; 
    struct Figura pionek [2] = {{"P", 1, 1, pionek_r},{"P", 2, 1, pionek_r}};
    struct Figura empty = {" "};
    struct Kolor zespol[2];
    for (l=0; l<2; l++){
        zespol[l].pion = malloc(8*sizeof(struct Figura));
    }

    zespol[0].pion[0].x = 1;
    zespol[0].pion[0].y = 1;
    zespol[0].pion[0].symbol="P";
    zespol[0].pion[1].symbol="P";
    zespol[0].pion[0].ruch = pionek_r;
    zespol[0].pion[1].ruch = pionek_r;
    
    

    int **szachownica =(int**)malloc(8*sizeof(int*)); 
    for(k=0; k<8; k++)
        szachownica[k]=(int*)malloc(8*sizeof(int));
    for (i=7; i>=0; i--){
    for(j=0; j<8; j++){
        szachownica[j][i]=empty.symbol[0];
    }
    
}
    

/*wstaw (szachownica, pionek[0]);
wstaw (szachownica, pionek[1]);
wyswietl(szachownica);
przesun(szachownica, &zespol[0].pion[0], zespol[0].pion[0].ruch[0]);
przesun(szachownica, &pionek[1], pionek[1].ruch[1]);
wyswietl(szachownica);
file_send(szachownica);*/
file_download(szachownica, zespol);
wyswietl(szachownica);
   
free(szachownica);



    return 0;
}