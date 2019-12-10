#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"

#define LR_PIONEK 2
#define LR_WIERZA 28
#define LR_GONIEC 28
#define LR_SKOCZEK 8
#define LR_HETMAN 56
#define LR_KROL 8
#define PIONEK bierka[0]
#define SKOCZEK bierka[1]
#define GONIEC bierka[2]
#define WIERZA bierka[3]
#define HETMAN bierka[4]
#define KROL bierka[5]


int main(int argc, char **argv){
    int i, j, k, l, w, m;
     
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
    
struct Wektor pionek_r[2] = {{0,1},{0,2}};
struct Wektor pionek_r2[2] = {{0,-1},{0,-2}};
struct Wektor wierza_r[28] = {{0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7},
                            {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},
                            {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},
                            {-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0}};
struct Wektor goniec_r[28] = {{-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7},
                            {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},
                            {1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7},
                            {-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7}};
struct Wektor skoczek_r[8] = {{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,-2},{-1,2}};
struct Wektor hetman_r[56] = {{0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7},
                            {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},
                            {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},
                            {-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0},
                            {-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7},
                            {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},
                            {1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7},
                            {-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7}};
struct Wektor krol_r[8] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{0,-1},{-1,0}};
    
    for (w=0; w<8; w++){
        zespol[0].PIONEK[w].symbol="P";
        zespol[0].PIONEK[w].ruch = pionek_r;
        zespol[0].PIONEK[w].l_ruchow= 2;

        zespol[1].PIONEK[w].symbol="p";
        zespol[1].PIONEK[w].ruch = pionek_r2;
        zespol[1].PIONEK[w].l_ruchow = 2;
    }
    for (m=0; m<2; m++){
        zespol[0].WIERZA[m].symbol="W";
        zespol[0].WIERZA[m].ruch = wierza_r;
        zespol[0].WIERZA[m].l_ruchow = 28;

        zespol[1].WIERZA[m].symbol="w";
        zespol[1].WIERZA[m].ruch = wierza_r;
        zespol[1].WIERZA[m].l_ruchow = 28;

        zespol[0].SKOCZEK[m].symbol="S";
        zespol[0].SKOCZEK[m].ruch = skoczek_r;
        zespol[0].SKOCZEK[m].l_ruchow = 8;

        zespol[1].SKOCZEK[m].symbol="s";
        zespol[1].SKOCZEK[m].ruch = skoczek_r;
        zespol[1].SKOCZEK[m].l_ruchow = 8;

        zespol[0].GONIEC[m].symbol="G";
        zespol[0].GONIEC[m].ruch = goniec_r;
        zespol[0].GONIEC[m].l_ruchow = 28;

        zespol[1].GONIEC[m].symbol="g";
        zespol[1].GONIEC[m].ruch = goniec_r;
        zespol[1].GONIEC[m].l_ruchow = 28;
    }
    zespol[0].HETMAN[0].symbol="H";
    zespol[0].HETMAN[0].ruch = hetman_r;
    zespol[0].HETMAN[0].l_ruchow = 56;
    zespol[1].HETMAN[0].symbol="h";
    zespol[1].HETMAN[0].ruch = hetman_r;
    zespol[1].HETMAN[0].l_ruchow = 56;

    zespol[0].KROL[0].symbol="K";
    zespol[0].KROL[0].ruch = krol_r;
    zespol[0].KROL[0].l_ruchow = 8;

    zespol[1].KROL[0].symbol="k";
    zespol[1].KROL[0].ruch = krol_r;
    zespol[1].KROL[0].l_ruchow = 8;


    
    

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
file_download(argv[1],szachownica, zespol);
wyswietl(szachownica);
przesun(szachownica, &zespol[0].PIONEK[2], zespol[0].PIONEK[2].ruch[1]);
wyswietl(szachownica);
przesun(szachownica, &zespol[1].PIONEK[7], zespol[1].PIONEK[7].ruch[1]);
wyswietl(szachownica);

//file_send(argv[1], szachownica);

   
free(szachownica);



    return 0;
}