#include <iostream>
#include <cmath>

class Zespolona
{
private:
    double real;
    double imag;
public:
    
    Zespolona(double r, double i)
    {
        real=r;
        imag=i;
    }

    friend std::ostream& operator<<(std::ostream& os, Zespolona const& complex);
    friend std::istream& operator>> (std::istream &in, Zespolona &complex);
    Zespolona operator+(Zespolona const& x)
    {
        Zespolona result(this->real + x.real, this->imag + x.imag);
        return result;
    }

    Zespolona operator-(Zespolona const& x)
    {
        Zespolona result(this->real - x.real, this->imag - x.imag);
        return result;
    }
    
    Zespolona operator*(Zespolona const& x)
    {
        Zespolona result(this->real*x.real - this->imag*x.imag, this->real*x.imag + this->imag*x.real);
        return result;
    }

    Zespolona operator/(Zespolona const& x)
    {
        Zespolona result( (this->real*x.real + this->imag*x.imag)/(pow(x.real,2) + pow(x.imag,2)), (this->imag*x.real - this->real*x.imag)/(pow(x.real,2) + pow(x.imag,2)) );
        return result;
    }

};

std::ostream& operator<<(std::ostream& os, Zespolona const& complex)
{
    os <<"("<< complex.real << "," << complex.imag <<"i)";
    return os;
}

std::istream& operator>> (std::istream &in, Zespolona &complex)
{
    std::cout << "Podaj część rzeczywistą";
    in >> complex.real;
    std::cout << "Podaj część zespoloną";
    in >> complex.imag;
    return in;
}

int main()
{
    Zespolona a(3,2);
    Zespolona b(2,6);
    
    std::cout<<a<<"\n";
    std::cout<<a+b<<"\n";
    std::cout<<a*b<<"\n";
    std::cout<<a/b<<"\n";

    return 0;
}