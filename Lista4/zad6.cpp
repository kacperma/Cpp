#include <iostream>
using namespace std;

class X
{
    friend std::ostream& operator << (std::ostream & F, X const&);
private:
    int _x;
public:
    X(int arg) : _x(arg){}
};

std::ostream& operator << (std::ostream & F, X const & arg)
{
    //nie da się w przeciążonym operatorze po prostu wypisać obiektu
    return F << arg._x;
}
int main()
{
    X zmienna(5);
    cout << zmienna << endl;
    return 0;
}