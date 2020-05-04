#include <iostream>
#include "stos.h"

int main()
{
    Stos test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    std::cout<<test<<"\n";
    return 0;
}