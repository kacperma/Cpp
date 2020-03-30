#include <iostream>
#include <vector>
#include <climits>

int minVect(std::vector<int> vect)
{
    if(vect.empty()==true)
        return INT_MIN;
    else
    {
        int min;
        for(int i=0; i<vect.size(); i++ )
        {
            if(i==0)
                min=vect[i];
            else
            {
                if(vect[i]<min)
                    min=vect[i];
            }
        } 
        return min;
    }
}

int main()
{
    std::vector<int> vect;
    std::cout<<minVect(vect)<<"\n";
    
    std::vector<int> vect2{2,6,123,321,9,-32,0,-64};
    std::cout<<minVect(vect2)<<"\n";
    return 0;
}