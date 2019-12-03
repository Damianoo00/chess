#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"

#define PIONEK bierka[0]
#define SKOCZEK bierka[1]
#define GONIEC bierka[2]
#define WIERZA bierka[3]
#define HETMAN bierka[4]
#define KROL bierka[5]


int main(){
    int i, j, k, l, w, m;
    struct Wektor pionek_r[2] = {{0,1},{0,2}}; 
    struct Figura empty = {" "};
    struct Kolor zespol[2];
    zespol[0].bierka = malloc(6*sizeof(struct Figura));
    zespol[1].bierka = malloc(6*sizeof(struct Figura));
    for (l=0; l<2; l++){
        zespol[l].PIONEK = malloc(8*sizeof(struct Figura));
        zespol[l].SKOCZEK = malloc(2*sizeof(struct Figura));
        zespol[l].GONIEC = malloc(2*sizeof(struct Figura));
        zespol[l].WIERZA = malloc(2*sizeof(struct Figura));
        zespol[l].HETMAN = malloc(1*sizeof(struct Figura));
        zespol[l].KROL = malloc(1*sizeof(struct Figura));
        
    }
    

    for (w=0; w<8; w++){
        zespol[0].PIONEK[w].symbol="P";
        zespol[1].PIONEK[w].symbol="p";
    }
    for (m=0; m<2; m++){
        zespol[0].WIERZA[m].symbol="W";
        zespol[1].WIERZA[m].symbol="w";
        zespol[0].SKOCZEK[m].symbol="S";
        zespol[1].SKOCZEK[m].symbol="s";
        zespol[0].GONIEC[m].symbol="G";
        zespol[1].GONIEC[m].symbol="g";
    }
    zespol[0].HETMAN[0].symbol="H";
    zespol[1].HETMAN[0].symbol="h";

    zespol[0].KROL[0].symbol="K";
    zespol[1].KROL[0].symbol="k";


    
    

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
przesun(szachownica, &zespol[0].PIONEK[2], pionek_r[1]);
wyswietl(szachownica);
przesun(szachownica, &zespol[0].PIONEK[7], pionek_r[0]);
wyswietl(szachownica);
file_send(szachownica);

   
free(szachownica);



    return 0;
}