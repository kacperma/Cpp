#include <iostream>
#include "stos.h"

int main()
{
    Stos test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    Stos abc(test);
    Stos efg = test;
    std::cout<<"\ntest size "<< test.size()<<" top element "<<test.top() << "\nabc size "<< abc.size()<<" top element "<< abc.top() << "\nefg size "<< efg.size()<<" top element " <<efg.top();
    test.push(5);
    abc.push(6);
    std::cout<<"\n\ntest size "<< test.size()<<" top element "<<test.top() << "\nabc size "<< abc.size()<<" top element "<< abc.top() << "\nefg size "<< efg.size()<<" top element " <<efg.top();
    
    return 0;
}