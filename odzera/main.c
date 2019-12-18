#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bibl.h"

#define PIONEK bierka[0]
#define SKOCZEK bierka[1]
#define GONIEC bierka[2]
#define WIERZA bierka[3]
#define HETMAN bierka[4]
#define KROL bierka[5]

int main(int argc, char **argv){
    int l;
    struct Szachownica szachownica;
    szachownica.zespol=malloc(2*sizeof(struct Kolor));
    
    szachownica.zespol[0].bierka = malloc(6*sizeof(struct Figura));
    szachownica.zespol[1].bierka = malloc(6*sizeof(struct Figura));
    for (l=0; l<2; l++){
        szachownica.zespol[l].PIONEK = malloc(8*sizeof(struct Figura));
        szachownica.zespol[l].SKOCZEK = malloc(2*sizeof(struct Figura));
        szachownica.zespol[l].GONIEC = malloc(2*sizeof(struct Figura));
        szachownica.zespol[l].WIERZA = malloc(2*sizeof(struct Figura));
        szachownica.zespol[l].HETMAN = malloc(1*sizeof(struct Figura));
        szachownica.zespol[l].KROL = malloc(1*sizeof(struct Figura));
        
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
    
    
        szachownica.zespol[0].PIONEK->symbol="P";
        szachownica.zespol[0].PIONEK->ruch = pionek_r;
        szachownica.zespol[0].PIONEK->l_ruchow= 2;
        szachownica.zespol[0].PIONEK->il_bierek= 8;
        
        szachownica.zespol[1].PIONEK->symbol="p";
        szachownica.zespol[1].PIONEK->ruch = pionek_r2;
        szachownica.zespol[1].PIONEK->l_ruchow = 2;
        szachownica.zespol[1].PIONEK->il_bierek = 8;

        szachownica.zespol[0].WIERZA->symbol="W";
        szachownica.zespol[0].WIERZA->ruch = wierza_r;
        szachownica.zespol[0].WIERZA->l_ruchow = 28;
        szachownica.zespol[0].WIERZA->il_bierek = 2;

        szachownica.zespol[1].WIERZA->symbol="w";
        szachownica.zespol[1].WIERZA->ruch = wierza_r;
        szachownica.zespol[1].WIERZA->l_ruchow = 28;
        szachownica.zespol[1].WIERZA->il_bierek = 2;

        szachownica.zespol[0].SKOCZEK->symbol="S";
        szachownica.zespol[0].SKOCZEK->ruch = skoczek_r;
        szachownica.zespol[0].SKOCZEK->l_ruchow = 8;
        szachownica.zespol[0].SKOCZEK->il_bierek = 2;

        szachownica.zespol[1].SKOCZEK->symbol="s";
        szachownica.zespol[1].SKOCZEK->ruch = skoczek_r;
        szachownica.zespol[1].SKOCZEK->l_ruchow = 8;
        szachownica.zespol[1].SKOCZEK->il_bierek = 2;

        szachownica.zespol[0].GONIEC->symbol="G";
        szachownica.zespol[0].GONIEC->ruch = goniec_r;
        szachownica.zespol[0].GONIEC->l_ruchow = 28;
        szachownica.zespol[0].GONIEC->il_bierek = 2;

        szachownica.zespol[1].GONIEC->symbol="g";
        szachownica.zespol[1].GONIEC->ruch = goniec_r;
        szachownica.zespol[1].GONIEC->l_ruchow = 28;
        szachownica.zespol[1].GONIEC->il_bierek = 2;
    
    szachownica.zespol[0].HETMAN->symbol="H";
    szachownica.zespol[0].HETMAN->ruch = hetman_r;
    szachownica.zespol[0].HETMAN->l_ruchow = 56;
    szachownica.zespol[0].HETMAN->il_bierek = 1;

    szachownica.zespol[1].HETMAN->symbol="h";
    szachownica.zespol[1].HETMAN->ruch = hetman_r;
    szachownica.zespol[1].HETMAN->l_ruchow = 56;
    szachownica.zespol[1].HETMAN->il_bierek = 1;

    szachownica.zespol[0].KROL->symbol="K";
    szachownica.zespol[0].KROL->ruch = krol_r;
    szachownica.zespol[0].KROL->l_ruchow = 8;
    szachownica.zespol[0].KROL->il_bierek = 1;

    szachownica.zespol[1].KROL->symbol="k";
    szachownica.zespol[1].KROL->ruch = krol_r;
    szachownica.zespol[1].KROL->l_ruchow = 8;
    szachownica.zespol[1].KROL->il_bierek = 2;

    


file_download(argv[1],&szachownica);

wyswietl(szachownica);

printf("%d",tablica_ruchow_ocena(szachownica, 0, szachownica.zespol[0], szachownica.zespol[1])); //207
//przesun(szachownica, &szachownica.zespol[0].bierka[0][1], szachownica.zespol[0].bierka[0]->ruch[1]);
//struct Wyznacznik alpha = {-1000, 0};
//struct Wyznacznik beta = {1000, 0};
//printf("%d",tablica_ruchow_ocena(szachownica, AlphaBeta(szachownica, 3, alpha, beta), szachownica.zespol[0], szachownica.zespol[1]));


wyswietl(szachownica);

//file_send(argv[1],szachownica);

    return 0;
}