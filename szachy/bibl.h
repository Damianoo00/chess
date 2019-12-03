struct Kolor{
    struct Figura *pion;
    struct Figura *skoczek;
    struct Figura *goniec;
    struct Figura *wierza;
    struct Figura *hetman;
    struct Figura *krol;
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




void wstaw(int **szachownica, struct Figura f);
void usun(int **szachownica, struct Figura f);
void przesun(int **szachownica, struct Figura *f, struct Wektor ruch);
void wyswietl(int **szachownica);
void file_send(int **szachownica);
void file_download(int **szachownica, struct Kolor *zespol);