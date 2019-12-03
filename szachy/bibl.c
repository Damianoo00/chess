#include <stdlib.h>
#include <stdio.h>
#include "bibl.h"




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
void przesun(int **szachownica, struct Figura *f, struct Wektor ruch){
    usun(szachownica, *f);
    f->x+=ruch.x;
    f->y+=ruch.y;
    wstaw(szachownica, *f);
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

void file_send(int **szachownica){
    int i, j;
    FILE *fin;
    fin = fopen("dane", "w");
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

void file_download(int **szachownica, struct Kolor *zespol){
    int i=8, j=0, licznik=0;
    char c;
     FILE *fin;
    fin = fopen("dane", "r");
    while((c = (fgetc(fin)))!= EOF){
            switch(c){
            case ' ':
                    j++;
             if(j>=8){
                 i--;
                    j=j%8;
            }
                break;
            case 'P':
                j++;
             if(j>=8){
                 i--;
                    j=j%8;
                    }

                    zespol[0].pion[licznik].x=j;
            zespol[0].pion[licznik].y=i;
            printf("%d %d\n", zespol[0].pion[licznik].x, zespol[0].pion[licznik].y);
        
            wstaw(szachownica, zespol[0].pion[licznik]);
            licznik++;
            break;
            default:
            break;

            }
            
        
    
    }
    
    
fclose(fin);
}