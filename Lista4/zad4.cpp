#include <iostream>
#include <fstream>
#include "random.h"

int main()
{
    Random x;
    std::ofstream myfile;
    myfile.open ("data.txt");
    for(int i=0;i<10000;i++)
    {
        myfile<<i<<" "<<x()<<"\n";
    }
    myfile.close();
    return 0;
}

//histogram został wykonany za pomąca programu gnuplot