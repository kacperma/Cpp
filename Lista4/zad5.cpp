#include <iostream>

class Samochod
{
public:
    Samochod(int n): _kola(n)//, this->_sruby=(4*n);
    {
        this->_sruby=4*_kola;
        std::cout<<"Samochod z "<<_kola<<" kolami i "<<_sruby<<" srubami\n";
    }
private:
    int _sruby;
    int _kola;
};

int main()
{
    Samochod s4 (4);
    Samochod s12(12);
}