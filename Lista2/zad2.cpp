#include <iostream>
#include <vector>

void zeroVect(std::vector<double>& vect)
{
    for(int i=0; i<vect.size(); i++)
    {
        vect[i]=0;
    }
    return;
}

int main()
{
    std::vector<double> vect{2.03,6.0,123.2,321.3,9.3,-32,0,-64};
    for(int i=0; i<vect.size(); i++)
    {
        std::cout<<vect[i]<<" ";
    }
    std::cout<<"\n";
    zeroVect(vect);

    for(int i=0; i<vect.size(); i++)
    {
        std::cout<<vect[i]<<" ";
    }
    return 0;
}