#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"

#define PIONEK bierka[0]
#define SKOCZEK bierka[1]
#define GONIEC bierka[2]
#define WIERZA bierka[3]
#define HETMAN bierka[4]
#define KROL bierka[5]

int w_bezwzgl (int x){
    if (x<0) return (-1)*x;
    return x;
}

void przesun(struct Szachownica szachownica, struct Figura *f, struct Wektor ruch, char **szach_pom){
        
    if (zasady_podstawowe(f->x, f->y,ruch.x, ruch.y, szach_pom)){
    f->x+=ruch.x;
    f->y+=ruch.y;
    }
}

int zakaz_przeskakiwania(int x, int y, int vx, int vy, char **szachownica){
    
    int i=0;
    if(vx!=0){
        if (vx>0) vx=vx-1;
        else vx=vx+1;
    }
    if(vy!=0){
        if (vy>0) vy=vy-1;
        else vy=vy+1;
    }
    while ((vx!=0 || vy!=0)){
        printf("Wartosc pola: %d",szachownica[(x-1)+vx][(y-1)+vy] );
        if (szachownica[(x-1)+vx][(y-1)+vy]!=32) return 0;
        if (vx>0) vx=vx-1;
        if (vx<0)vx=vx+1;
        if (vy>0) vy=vy-1;
        if (vy<0)vy=vy+1;
    }
    return 1;
    }
int zakaz_wchodzenia_na_wlasne_bierki(int x, int y, int vx, int vy, char **szachownica){
    
    if (w_bezwzgl(szachownica[x-1][y-1]-szachownica[(x-1)+vx][(y-1)+vy])<=16) return 0;
    printf("%c %c %c\n",szachownica[x-1][y-1],szachownica[(x-1)+vx][(y-1)+vy],  w_bezwzgl(szachownica[x-1][y-1]-szachownica[(x-1)+vx][(y-1)+vy]));
    return 1;
    }
int zakaz_wyjscia_poza_plansze(int x, int y, int vx, int vy){
    int i, j;
    if ((x+vx)<1 || (x+vx)>8) return 0;
    if ((y+vy)<1 || (y+vy)>8) return 0;
    return 1;
}

int zasady_podstawowe(int x, int y, int vx, int vy, char **szachownica){
    if (zakaz_wyjscia_poza_plansze(x, y, vx, vy)==0) return 0;
    //if (zakaz_wchodzenia_na_wlasne_bierki(x, y, vx, vy, szachownica)==0) return 0;
    //if (zakaz_przeskakiwania(x, y, vx, vy, szachownica)==0) return 0;
    
    return 1;
}



void wyswietl(struct Szachownica szachownica){
    int i, j, k, l ,m, pom;
    printf("\n");
    for (i=7; i>=0; i--){
        printf("|");
    for(j=0; j<8; j++){
        pom =0;
        for(k=0; k<2; k++){
        for(l = 0; l<6; l++){
        for(m=0; m<szachownica.zespol[k].bierka[l]->il_bierek; m++){
            
        if(szachownica.zespol[k].bierka[l][m].x == j+1 && szachownica.zespol[k].bierka[l][m].y==i+1){
            printf("%c", szachownica.zespol[k].bierka[l]->symbol[0]);
            pom++;
        }}}}
        if(pom==0)printf(" ");
        printf("|");
    }
    printf("\n");
}
}

void file_download(char *plik, struct Szachownica *szachownica){
    int i=8, j=0, licznik[12]={0,0,0,0,0,0,0,0,0,0,0,0}, d, k;
    char c;
     FILE *fin;
    fin = fopen(plik, "r");
    
    while((c = (fgetc(fin)))!= EOF){
        if(c!='|'&& c!='\n'){
         j++;
             if(j>8){
                 i--;
                    j=1;
            }
        
        for (d=0; d<6; d++){
            for(k=1; k>=0; k--){
            if (c==szachownica->zespol[k].bierka[d]->symbol[0]){
                szachownica->zespol[k].bierka[d][licznik[d*2+k]].x=j;
                szachownica->zespol[k].bierka[d][licznik[d*2+k]].y=i;
            printf("%c %d %d\n", szachownica->zespol[k].bierka[d]->symbol[0],szachownica->zespol[k].bierka[d][licznik[d*2+k]].x, szachownica->zespol[k].bierka[d][licznik[d*2+k]].y);
        
            
            licznik[d*2+k]++;

            }
            }
        }
    }
    }
           
        
fclose(fin);
}

int tablica_ruchow_ocena (struct Szachownica szachownica, int n, struct Kolor z, struct Kolor z2){
        int i, j, k, zl, licznik=0, ocena_p;
        char szach_pom[8][8];
int  m, d;
    for(d=7; d>=0; d--){
    for(m=0; m<8; m++){
        szach_pom[m][d] =0;
    for(i=0; i<2; i++)
    for(j=0; j<6; j++)
    for(k=0; k<szachownica.zespol[i].bierka[j]->il_bierek; k++){
        if (szachownica.zespol[i].bierka[j][k].x-1 == m && szachownica.zespol[i].bierka[j][k].y-1 == d){
       szach_pom[m][d]=szachownica.zespol[i].bierka[j]->symbol[0];
        
        }
        
      
    } 
    }
    }
    
        for (i=0; i<6; i++){
            
            for(j=0; j<z.bierka[i]->il_bierek; j++){
                for(k=0; k<z.bierka[i]->l_ruchow; k++){
                    if(licznik ==n){
                       //ocena_p = ocena(szach_pom, &z.bierka[i][j], z.bierka[i]->ruch[k], z2);
                    przesun(szachownica, &z.bierka[i][j], z.bierka[i]->ruch[k], szach_pom);
                    //return ocena_p;
                    }
                    licznik++;
                }
            }
        }
}

int ocena (char **szachownica, struct Figura *f, struct Wektor ruch, struct Kolor zespol_p){
    int i;
    if(f->x + ruch.x == zespol_p.KROL[0].x && f->y + ruch.y == zespol_p.KROL[0].y)
        return 100;
    
    if(f->x + ruch.x == zespol_p.HETMAN[0].x && f->y + ruch.y == zespol_p.HETMAN[0].y)
        return 50;
    
        for(i=0; i<2; i++){
            if(f->x + ruch.x == zespol_p.GONIEC[i].x && f->y + ruch.y == zespol_p.GONIEC[i].y)
            return 50;
            if(f->x + ruch.x == zespol_p.SKOCZEK[i].x && f->y + ruch.y == zespol_p.SKOCZEK[i].y)
            return 40;
            if(f->x + ruch.x == zespol_p.WIERZA[i].x && f->y + ruch.y == zespol_p.WIERZA[i].y)
            return 30;
        }

        for(i=0; i<8; i++){
            if(f->x + ruch.x == zespol_p.PIONEK[i].x && f->y + ruch.y == zespol_p.PIONEK[i].y)
            return 10;
            
        }
return 0;
    }

int AlphaBeta (struct Szachownica szachownica, int depth, struct Wyznacznik alpha, struct Wyznacznik beta)
{
    
    struct Szachownica szachownica_d;
    cpy_szach(&szachownica_d, szachownica);
    wyswietl(szachownica_d);
    int i;
    for(i=0; i<207; i++){
        printf("%d ", tablica_ruchow_ocena(szachownica_d, i, szachownica_d.zespol[0], szachownica_d.zespol[1]));
        alpha.ocena = tablica_ruchow_ocena(szachownica_d, i, szachownica_d.zespol[0], szachownica_d.zespol[1]);
        if (ocena==100 || depth ==0) return i;
        if (ocena > alpha.ocena){
            alpha.nr = i;
        }
        return AlphaBeta (szachownica_d, depth-1 , alpha, beta);
    }
    if(alpha.ocena >= beta.ocena){
        return 0;
    }
    return alpha.nr;

    for(i=0; i<207; i++){
        printf("%d ", tablica_ruchow_ocena(szachownica_d, i, szachownica_d.zespol[1], szachownica_d.zespol[0]));
        beta.ocena = tablica_ruchow_ocena(szachownica_d, i, szachownica_d.zespol[1], szachownica_d.zespol[0]);
        if (ocena==100 || depth ==0) return i;
        if (ocena < beta.ocena){
            beta.nr = i;
        }
        return AlphaBeta (szachownica_d, depth-1 , alpha, beta);
    }
    if(alpha.ocena >= beta.ocena){
        return 0;
    }
    return beta.nr;
}

void cpy_szach(struct Szachownica *sz_dest, struct Szachownica sz_source){
    int i,j,k,l;
    sz_dest->zespol=malloc(2*sizeof(struct Kolor));
    
    sz_dest->zespol[0].bierka = malloc(6*sizeof(struct Figura));
    sz_dest->zespol[1].bierka = malloc(6*sizeof(struct Figura));
    for (l=0; l<2; l++){
        sz_dest->zespol[l].PIONEK = malloc(8*sizeof(struct Figura));
        sz_dest->zespol[l].SKOCZEK = malloc(2*sizeof(struct Figura));
        sz_dest->zespol[l].GONIEC = malloc(2*sizeof(struct Figura));
        sz_dest->zespol[l].WIERZA = malloc(2*sizeof(struct Figura));
        sz_dest->zespol[l].HETMAN = malloc(1*sizeof(struct Figura));
        sz_dest->zespol[l].KROL = malloc(1*sizeof(struct Figura));
        
    }
for(i=0; i<2; i++){
for(j=0; j<6; j++){
    sz_dest->zespol[i].bierka[j]->symbol = sz_source.zespol[i].bierka[j]->symbol;
    sz_dest->zespol[i].bierka[j]->il_bierek = sz_source.zespol[i].bierka[j]->il_bierek;
    sz_dest->zespol[i].bierka[j]->l_ruchow = sz_source.zespol[i].bierka[j]->l_ruchow;
    sz_dest->zespol[i].bierka[j]->ruch = sz_source.zespol[i].bierka[j]->ruch;
for(k=0; k<sz_source.zespol[i].bierka[j]->il_bierek; k++){

sz_dest->zespol[i].bierka[j][k].y = sz_source.zespol[i].bierka[j][k].y;
sz_dest->zespol[i].bierka[j][k].x = sz_source.zespol[i].bierka[j][k].x;
}}}
}

void file_send(char *plik, struct Szachownica szachownica){
    FILE *fin;
    fin = fopen(plik, "w");
    int i, j, k, l ,m, pom;
    fprintf(fin,"\n");
    for (i=7; i>=0; i--){
        fprintf(fin,"|");
    for(j=0; j<8; j++){
        pom =0;
        for(k=0; k<2; k++){
        for(l = 0; l<6; l++){
        for(m=0; m<szachownica.zespol[k].bierka[l]->il_bierek; m++){
            
        if(szachownica.zespol[k].bierka[l][m].x == j+1 && szachownica.zespol[k].bierka[l][m].y==i+1){
            fprintf(fin,"%c", szachownica.zespol[k].bierka[l]->symbol[0]);
            pom++;
        }}}}
        if(pom==0)fprintf(fin," ");
        fprintf(fin,"|");
    }
    fprintf(fin,"\n");
}
fclose(fin);
}