#include <iostream>
#include <vector>

double zad6(double *tab,int n)
{
    return 6.9;
}


int main()
{
    //1)
    double (*arr)[100];

    //2)
    char *charArr[5][5];

    //---3)
    int n;
    const char *zad3 =new char[n];
    delete [] zad3;

    //4)
    std::vector <void *> zad4;

    //5)
    std::vector <double> zad5[4];

    //6)
    double (*zad6pointer)(double*,int) = &zad6;

    //7
    void f(int*&);


    return 0;
}