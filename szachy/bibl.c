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
int zakaz_przeskakiwania(int x, int y, int vx, int vy, int **szachownica){
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
       // printf("Wartosc pola: %d",szachownica[(x-1)+vx][(y-1)+vy] );
        if (szachownica[(x-1)+vx][(y-1)+vy]!=32) return 0;
        if (vx>0) vx=vx-1;
        if (vx<0)vx=vx+1;
        if (vy>0) vy=vy-1;
        if (vy<0)vy=vy+1;
    }
    return 1;
    }
int zakaz_wchodzenia_na_wlasne_bierki(int x, int y, int vx, int vy, int **szachownica){
    if (w_bezwzgl(szachownica[x-1][y-1]-szachownica[(x-1)+vx][(y-1)+vy])<=16) return 0;
    return 1;
    }
int zakaz_wyjscia_poza_plansze(int x, int y, int vx, int vy){
    int i, j;
    if ((x+vx)<1 || (x+vx)>8) return 0;
    if ((y+vy)<1 || (y+vy)>8) return 0;
    return 1;
}

int zasady_podstawowe(int x, int y, int vx, int vy, int **szachownica){
    if (zakaz_wyjscia_poza_plansze(x, y, vx, vy)==0) return 0;
    if (zakaz_wchodzenia_na_wlasne_bierki(x, y, vx, vy, szachownica)==0) return 0;
    if (zakaz_przeskakiwania(x, y, vx, vy, szachownica)==0) return 0;
    if(x==0 || y==0) return 0;
    
    return 1;
}
void przesun(int **szachownica, struct Figura *f, struct Wektor ruch){
    if (zasady_podstawowe(f->x, f->y,ruch.x, ruch.y, szachownica)){
    usun(szachownica, *f);
    f->x+=ruch.x;
    f->y+=ruch.y;
    wstaw(szachownica, *f);
}
}

void wyswietl(int **szachownica){
    int i, j;
    printf("\n");
    for (i=7; i>=0; i--){
        printf("|");
    for(j=0; j<8; j++){
        
        printf("%c", szachownica[j][i]);
        printf("|");
    }
    printf("\n");
}
}

void file_send(char *plik, int **szachownica){
    int i, j;
    FILE *fin;
    fin = fopen(plik, "w");
    fprintf(fin, "\n");
    for (i=7; i>=0; i--){
        fprintf(fin, "|");
    for(j=0; j<8; j++){
        
        fprintf(fin, "%c", szachownica[j][i]);
        fprintf(fin, "|");
    }
    fprintf(fin, "\n");
}
fclose(fin);
}

void file_download(char *plik, int **szachownica, struct Kolor *zespol){
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
            if (c==zespol[k].bierka[d]->symbol[0]){
                zespol[k].bierka[d][licznik[d*2+k]].x=j;
            zespol[k].bierka[d][licznik[d*2+k]].y=i;
            printf("%c %d %d\n", zespol[k].bierka[d]->symbol[0],zespol[k].bierka[d][licznik[d*2+k]].x, zespol[k].bierka[d][licznik[d*2+k]].y);
        
            wstaw(szachownica, (zespol[k].bierka[d][licznik[d*2+k]]));
            licznik[d*2+k]++;

            }
            }
        }
    }
    }
           
        
fclose(fin);
}



int ocena (int **szachownica, struct Figura *f, struct Wektor ruch, struct Kolor zespol_p){
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

void tablica_ruchow (int **szachownica, int n, struct Kolor z){
        int i, j, k, zl, licznik=0;
        for (i=0; i<6; i++){
            
            for(j=0; j<z.bierka[i]->il_bierek; j++){
                for(k=0; k<z.bierka[i]->l_ruchow; k++){
                    if(licznik ==n)
                    przesun(szachownica, &z.bierka[i][j], z.bierka[i]->ruch[k]);
                    licznik++;
                }
            }
        }
}



