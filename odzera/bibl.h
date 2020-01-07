#ifndef _BIBL_H
#define _BIBL_H

struct Szachownica{
    struct Kolor *zespol;
};
struct Kolor{
    struct Figura **bierka;
};
struct Figura{
    char *symbol;
    int il_bierek;
    int x;
    int y;
    struct Wektor *ruch;
    int l_ruchow;
};
struct Wektor{
    int x;
    int y;
};
struct Wyznacznik{
    int ocena;
    int nr;
}; 


void file_send(struct Szachownica szachownica);
int w_bezwzgl (int x);
void przesun(struct Szachownica szachownica, struct Figura *f, struct Wektor ruch, char szach_pom[8][8]);
void wyswietl(struct Szachownica szachownica);
int tablica_ruchow_ocena (struct Szachownica szachownica, int n, struct Kolor z, struct Kolor z2);
void file_download(char *plik, struct Szachownica *szachownica);
int zakaz_przeskakiwania(int x, int y, int vx, int vy, char szachownica[8][8]);
int zakaz_wchodzenia_na_wlasne_bierki(int x, int y, int vx, int vy, char szachownica[8][8]);
int zasady_podstawowe(int x, int y, int vx, int vy, char szachownica[8][8]);
int zakaz_wyjscia_poza_plansze(int x, int y, int vx, int vy);
int ocena (char **szachownica, struct Figura *f, struct Wektor ruch, struct Kolor zespol_p);
void cpy_szach(struct Szachownica *sz_dest, struct Szachownica sz_source);
struct Wyznacznik alfabeta( struct Szachownica szachownica, struct Wyznacznik alpha, struct Wyznacznik beta, int depthleft, int n );

#endif