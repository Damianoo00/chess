#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"
#include "bibl.c"

#define PIONEK bierka[0]
#define SKOCZEK bierka[1]
#define GONIEC bierka[2]
#define WIERZA bierka[3]
#define HETMAN bierka[4]
#define KROL bierka[5]

int alfabetaMAX(int **szachownica, int ocena_ruchu, struct Kolor *zespol, int  glebokosc,int alfa,int beta){
    if (glebokosc == 0 || ocena_ruchu == 100) return ocena_ruchu;

    int i, j, ocena_ruchu;
    for (i=0; i<8; i++){
        for (j=0; j<zespol[0].PIONEK[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].PIONEK[i] , zespol[0].PIONEK[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].PIONEK[i], zespol[0].PIONEK[i].ruch[j]);
        ocena_ruchu = alfabetaMIN(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu >= beta )
         return beta;
         if( ocena_ruchu > alfa )
         alfa = ocena_ruchu;

    }}

    for (i=0; i<2; i++){
        for (j=0; j<zespol[0].WIERZA[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].WIERZA[i] , zespol[0].WIERZA[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].WIERZA[i], zespol[0].WIERZA[i].ruch[j]);
        ocena_ruchu = alfabetaMIN(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu >= beta )
         return beta;
         if( ocena_ruchu > alfa )
         alfa = ocena_ruchu;
        }
        for (j=0; j<zespol[0].SKOCZEK[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].SKOCZEK[i] , zespol[0].SKOCZEK[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].SKOCZEK[i], zespol[0].SKOCZEK[i].ruch[j]);
        ocena_ruchu = alfabetaMIN(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu >= beta )
         return beta;
         if( ocena_ruchu > alfa )
         alfa = ocena_ruchu;
        }
        for (j=0; j<zespol[0].GONIEC[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].GONIEC[i] , zespol[0].GONIEC[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].GONIEC[i], zespol[0].GONIEC[i].ruch[j]);
        ocena_ruchu = alfabetaMIN(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu >= beta )
         return beta;
         if( ocena_ruchu > alfa )
         alfa = ocena_ruchu;
        }

    }
    ocena_ruchu = ocena(szachownica, &zespol[0].HETMAN[i] , zespol[0].HETMAN[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].HETMAN[i], zespol[0].HETMAN[i].ruch[j]);
        ocena_ruchu = alfabetaMIN(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu >= beta )
         return beta;
         if( ocena_ruchu > alfa )
         alfa = ocena_ruchu;

    ocena_ruchu = ocena(szachownica, &zespol[0].KROL[i] , zespol[0].KROL[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].KROL[i], zespol[0].KROL[i].ruch[j]);
        ocena_ruchu = alfabetaMIN(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu >= beta )
         return beta;
         if( ocena_ruchu > alfa )
         alfa = ocena_ruchu;
   
    
    
   
    return alfa;
}

int alfabetaMIN(int **szachownica, int ocena_ruchu, struct Kolor *zespol, int  glebokosc,int alfa,int beta){
    if (glebokosc == 0 || ocena_ruchu == 100) return ocena_ruchu;

    int i, j, ocena_ruchu;
    for (i=0; i<8; i++){
        for (j=0; j<zespol[0].PIONEK[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].PIONEK[i] , zespol[0].PIONEK[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].PIONEK[i], zespol[0].PIONEK[i].ruch[j]);
        ocena_ruchu = alfabetaMAX(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu <= alfa )
         return alfa;
         if( ocena_ruchu < beta )
         beta = ocena_ruchu;

    }}

    for (i=0; i<2; i++){
        for (j=0; j<zespol[0].WIERZA[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].WIERZA[i] , zespol[0].WIERZA[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].WIERZA[i], zespol[0].WIERZA[i].ruch[j]);
        ocena_ruchu = alfabetaMAX(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu <= alfa )
         return alfa;
         if( ocena_ruchu < beta )
         beta = ocena_ruchu;
        }
        for (j=0; j<zespol[0].SKOCZEK[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].SKOCZEK[i] , zespol[0].SKOCZEK[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].SKOCZEK[i], zespol[0].SKOCZEK[i].ruch[j]);
        ocena_ruchu = alfabetaMAX(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu <= alfa )
         return alfa;
         if( ocena_ruchu < beta )
         beta = ocena_ruchu;
        }
        for (j=0; j<zespol[0].GONIEC[i].l_ruchow; j++){
            ocena_ruchu = ocena(szachownica, &zespol[0].GONIEC[i] , zespol[0].GONIEC[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].GONIEC[i], zespol[0].GONIEC[i].ruch[j]);
        ocena_ruchu = alfabetaMAX(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu <= alfa )
         return alfa;
         if( ocena_ruchu < beta )
         beta = ocena_ruchu;
        }

    }
    ocena_ruchu = ocena(szachownica, &zespol[0].HETMAN[i] , zespol[0].HETMAN[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].HETMAN[i], zespol[0].HETMAN[i].ruch[j]);
        ocena_ruchu = alfabetaMAX(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu <= alfa )
         return alfa;
         if( ocena_ruchu < beta )
         beta = ocena_ruchu;

    ocena_ruchu = ocena(szachownica, &zespol[0].KROL[i] , zespol[0].KROL[i].ruch[j], zespol[0]);
        przesun(szachownica, &zespol[0].KROL[i], zespol[0].KROL[i].ruch[j]);
        ocena_ruchu = alfabetaMAX(szachownica, ocena_ruchu, zespol, glebokosc-1, alfa, beta);
        if( ocena_ruchu <= alfa )
         return alfa;
         if( ocena_ruchu < beta )
         beta = ocena_ruchu;
   
    
    
   
    return beta;
}