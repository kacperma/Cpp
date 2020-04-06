#include <cstdlib>

class Wektor
{
private:
    size_t _rozmiar;
    int * _ptab;
public:
    Wektor(size_t n) :_rozmiar(0), _ptab(0){}
    ~Wektor()
    {
        delete [] _ptab;
    }
    size_t size() const
    {
        return _rozmiar;
    }
    int & operator[](int n)
    {
        return _ptab[n];
    }
    int operator[](int n) const
    {
        return _ptab[n];
    }

    void operator=(Wektor const& wek);
};
