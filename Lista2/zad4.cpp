#include <iostream>

unsigned silnia(unsigned n)
{
    if(n == 0)
        return 1;
    else
    {
        return n * silnia(n-1);
    }
}

int main()
{
    //wartość -1 jest przypisana do zmiennej typu unsigned co powoduje "zapętlenie" i wartość zmiennej n nie jest -1 a UINT_MAX-1  (4294967294)
    std::cout<<"-1!= "<<silnia(-1)<<"\n";
    return 0;
}
