#include <iostream>
#include "random.h"

int main()
{
    Random x;
    for(int i=0;i<10;i++)
    {
        std::cout<<x()<<"\n";
    }
    return 0;
}