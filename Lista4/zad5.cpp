#include <iostream>

class Samochod
{
public:
    Samochod(int n): _kola(n)//, this->_sruby=(4*n);  należy zamienić _kola na n aby wynik był poprawny lub całą formułe this->_sruby=4*_kola wrzucić do środka konstruktora
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