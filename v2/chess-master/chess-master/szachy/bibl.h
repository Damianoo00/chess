struct Kolor{
    struct Figura **bierka;
};
struct Figura{
    char *symbol;
    int x;
    int y;
    struct Wektor *ruch;
};
struct Wektor{
    int x;
    int y;
};


int zakaz_przeskakiwania(int x, int y, int vx, int vy, int **szachownica);
int zakaz_wchodzenia_na_wlasne_bierki(int x, int y, int vx, int vy, int **szachownica);
int zasady_podstawowe(int x, int y, int vx, int vy, int **szachownica);
int zakaz_wyjscia_poza_plansze(int x, int y, int vx, int vy);
void wstaw(int **szachownica, struct Figura f);
void usun(int **szachownica, struct Figura f);
void przesun(int **szachownica, struct Figura *f, struct Wektor ruch);
void wyswietl(int **szachownica);
void file_send(int **szachownica);
void file_download(int **szachownica, struct Kolor *zespol);
void file_download_v2(int **szachownica, struct Kolor *zespol);