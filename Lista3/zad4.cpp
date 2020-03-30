#include <iostream>

int main()
{
    double tab[10];
    double x;
    std::cout<<&x<<"\t"<<&tab[-1]<<"\n";
    return 0;
}

//u mnie adres różni się od tego w książce: 0x61fec8
//niepoprawene indeksowanie tablicy może zwrócić adres innej zmiennej
//&tab[-1] zwraca adres komórki w której znajduje się x