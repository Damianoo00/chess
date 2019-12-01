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