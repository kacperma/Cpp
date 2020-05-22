#include "ppmimage.h"
#include <ios>
#include <fstream>
#include <cmath>

#define M_PI 3.14159265358979323846
PPMimage::PPMimage(const char nazwa_pliku[])
{
    std::ifstream F(nazwa_pliku, std::ios::binary);
    std::string s;
    F >> s >> std::ws;
    while(F.peek() == '#')
        F.ignore(100000,'\n');
    F >> szerokosc >> wysokosc >> glebia;
    F.ignore(100000,'\n');
    tab = new Kolor*[wysokosc];
    for(int i = 0; i < wysokosc; ++i)
    {
        tab[i] = new Kolor[szerokosc];
        char* adres = reinterpret_cast<char*>(tab[i]);
        F.read(adres, sizeof(Kolor) * szerokosc);
    }
}

void PPMimage::znieksztalc(int param_x, int param_y)
{
    Kolor* p = new Kolor[szerokosc];
    for(int y = 0; y< wysokosc; ++y)
    {
        int dx = int(0.5 + param_x / 2.0 * sin(2 * M_PI * y / param_y));
        for(int x = 0; x < szerokosc ; x++)
        {
            int index = (x + dx) % szerokosc;
            if(index < 0)
                index += szerokosc;
            p[x] = tab[y][index];
        }
        std::swap(tab[y], p);
    }
    delete [] p;
}


void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n" << szerokosc << " " << wysokosc << "\n" << glebia << "\n";
    for(int i = 0; i < wysokosc; ++i)
        F.write(reinterpret_cast<char*>(tab[i]), 3 * szerokosc);
}
//                                                  ZADANIE
void PPMimage::zapiszpgm(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    unsigned char* x = new unsigned char[szerokosc];
    F << "P5\n" << szerokosc << " " << wysokosc << "\n" << glebia << "\n";
    for(int i = 0; i < wysokosc; ++i)
    {
        for(int j = 0; j < szerokosc; j++)
            x[j] = floor((tab[i][j].red + tab[i][j].green + tab[i][j].blue)/3);
        F.write(reinterpret_cast<char*>(x), szerokosc);
    }
}
//                                                  ZADANIE
PPMimage::~PPMimage()
{
    for(int i = 0; i < wysokosc; ++i)
        delete [] tab[i];
    delete [] tab;
}
