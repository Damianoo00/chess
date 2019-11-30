struct Figura{
    char *symbol;
    int x;
    int y;
    
};



void wstaw(int **szachownica, struct Figura f);
void usun(int **szachownica, struct Figura f);
void przesun(int **szachownica, struct Figura *f, int x, int y);
void wyswietl(int **szachownica);