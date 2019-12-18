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

void file_send(char *plik, struct Szachownica szachownica);
int w_bezwzgl (int x);
void przesun(struct Szachownica szachownica, struct Figura *f, struct Wektor ruch, char **szach_pom);
void wyswietl(struct Szachownica szachownica);
int tablica_ruchow_ocena (struct Szachownica szachownica, int n, struct Kolor z, struct Kolor z2);
void file_download(char *plik, struct Szachownica *szachownica);
int zakaz_przeskakiwania(int x, int y, int vx, int vy, char **szachownica);
int zakaz_wchodzenia_na_wlasne_bierki(int x, int y, int vx, int vy, char **szachownica);
int zasady_podstawowe(int x, int y, int vx, int vy, char **szachownica);
int zakaz_wyjscia_poza_plansze(int x, int y, int vx, int vy);
int ocena (char **szachownica, struct Figura *f, struct Wektor ruch, struct Kolor zespol_p);
int AlphaBeta (struct Szachownica szachownica, int depth, struct Wyznacznik alpha, struct Wyznacznik beta);
void cpy_szach(struct Szachownica *sz_dest, struct Szachownica sz_source);