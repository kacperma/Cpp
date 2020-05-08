#include <iostream>

class Dwa
{
public:
    Dwa()
    {
        std::cout << "Kolejnośc";
    }
    ~Dwa()
    {
        std::cout << " \n";
    }
};

class Trzy
{
public:
    Trzy()
    {
        std::cout << " i";
    }
    ~Trzy()
    {
        std::cout << " objektów";
    }
};

class Cztery
{
public:
    Cztery()
    {
        std::cout << " konstrukcji";
    }
    ~Cztery()
    {
        std::cout << " logiczna";
    }
};


class Raz: public Dwa
{
public:
    Raz()
    {
        Trzy trzy;
        std::cout << " destrukcji";
    }
    ~Raz()
    {
        std::cout << " jest";
    }
private:
    Cztery _cztery;
};

// 2k           4k       3k     1k      3d      1d      4d      2d
// Kolejnosc konstrukcji i destruckji obiektów jest logiczna    \n
int main()
{
    Raz raz;
    return 0;
}

