struct Kolor{
    struct Figura *pion[8];
    struct Figura *skoczek[2];
    struct Figura *goniec[2];
    struct Figura *wierza[2];
    struct Figura *hetman[1];
    struct Figura *krol[1];
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