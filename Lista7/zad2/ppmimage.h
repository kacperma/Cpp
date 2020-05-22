class PPMimage
{
public:
    struct Kolor{unsigned char red, green, blue;};

    PPMimage(const char nazwa_pliku[]);
    ~PPMimage();

    void zapisz(const char nazwa_pliku[]);
    void znieksztalc(int param_x, int param_y);
    void zapiszpgm(const char nazwa_pliku[]);
     
private:
    PPMimage(PPMimage const&){}
    void operator=(PPMimage const&){}

    int szerokosc;
    int wysokosc;
    int glebia;
    Kolor** tab;
};