#include "ppmimage.h"
#include <ios>
#include <fstream>
#include <cmath>
#include <iostream>

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
//                                                      ZADANIE
void PPMimage::zmiekcz()
{
    Kolor* p = new Kolor[szerokosc];
    unsigned char r,g,b;
    for(int y = 0; y < wysokosc; ++y)
    {
        for(int x = 0; x < szerokosc; x++)
        {
            if(x == 0 && y != 0 && y != wysokosc-1)
            {
                r = (tab[y][x+1].red + tab[y][x].red + tab[y-1][x].red + tab[y+1][x].red)/4;
                g = (tab[y][x+1].green + tab[y][x].green + tab[y-1][x].green + tab[y+1][x].green)/4;
                b = (tab[y][x+1].blue + tab[y][x].blue + tab[y-1][x].blue + tab[y+1][x].blue)/4;
            }
            else if(x == szerokosc-1 && y != 0 && y != wysokosc-1)
            {
                r = (tab[y][x-1].red + tab[y][x].red + tab[y-1][x].red + tab[y+1][x].red)/4;
                g = (tab[y][x-1].green + tab[y][x].green + tab[y-1][x].green + tab[y+1][x].green)/4;
                b = (tab[y][x-1].blue + tab[y][x].blue + tab[y-1][x].blue + tab[y+1][x].blue)/4;
            }
            else if(y == 0 && x != 0 && x != szerokosc-1)
            {
                r = (tab[y+1][x].red + tab[y][x].red + tab[y][x-1].red + tab[y][x+1].red)/4;
                g = (tab[y+1][x].green + tab[y][x].green + tab[y][x-1].green + tab[y][x+1].green)/4;
                b = (tab[y+1][x].blue + tab[y][x].blue + tab[y][x-1].blue + tab[y][x+1].blue)/4;
            }
            else if(y == wysokosc-1 && x != 0 && x != szerokosc-1)
            {
                r = (tab[y-1][x].red + tab[y][x].red + tab[y][x-1].red + tab[y][x+1].red)/4;
                g = (tab[y-1][x].green + tab[y][x].green + tab[y][x-1].green + tab[y][x+1].green)/4;
                b = (tab[y-1][x].blue + tab[y][x].blue + tab[y][x-1].blue + tab[y][x+1].blue)/4;
            }
            else if(x == 0 && y == 0)
            {
                r = (tab[y+1][x].red + tab[y][x].red + tab[y][x+1].red)/3;
                g = (tab[y+1][x].green + tab[y][x].green + tab[y][x+1].green)/3;
                b = (tab[y+1][x].blue + tab[y][x].blue + tab[y][x+1].blue)/3;
            }
            else if(x == 0 && y == wysokosc-1)
            {
                r = (tab[y-1][x].red + tab[y][x].red + tab[y][x+1].red)/3;
                g = (tab[y-1][x].green + tab[y][x].green + tab[y][x+1].green)/3;
                b = (tab[y-1][x].blue + tab[y][x].blue + tab[y][x+1].blue)/3;
            }
            else if(x == szerokosc-1 && y == 0)
            {
                r = (tab[y+1][x].red + tab[y][x].red + tab[y][x-1].red)/3;
                g = (tab[y+1][x].green + tab[y][x].green + tab[y][x-1].green)/3;
                b = (tab[y+1][x].blue + tab[y][x].blue + tab[y][x-1].blue)/3;
            }
            else if(x == szerokosc-1 && y == wysokosc-1)
            {
                r = (tab[y-1][x].red + tab[y][x].red + tab[y][x-1].red)/3;
                g = (tab[y-1][x].green + tab[y][x].green + tab[y][x-1].green)/3;
                b = (tab[y-1][x].blue + tab[y][x].blue + tab[y][x-1].blue)/3;
            }
            else
            {
                r = (tab[y][x-1].red + tab[y][x].red + tab[y][x+1].red + tab[y-1][x].red + tab[y+1][x].red)/5;
                g = (tab[y][x-1].green + tab[y][x].green + tab[y][x+1].green + tab[y-1][x].green + tab[y+1][x].green)/5;
                b = (tab[y][x-1].blue + tab[y][x].blue + tab[y][x+1].blue + tab[y-1][x].blue + tab[y+1][x].blue)/5;
            }
            p[x] = {r,g,b};
        }
        std::swap(tab[y], p);
    }
    delete [] p;
}
//                                                      ZADANIE

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n" << szerokosc << " " << wysokosc << "\n" << glebia << "\n";
    for(int i = 0; i < wysokosc; ++i)
        F.write(reinterpret_cast<char*>(tab[i]), 3 * szerokosc);
}


PPMimage::~PPMimage()
{
    for(int i = 0; i < wysokosc; ++i)
        delete [] tab[i];
    delete [] tab;
}
