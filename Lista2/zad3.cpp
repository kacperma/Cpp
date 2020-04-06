#include <iostream>
#include <vector>
#include <climits>

double operator*(const std::vector<double>& self, const std::vector<double>& other)
{
    if(self.size() != other.size()) 
        throw std::logic_error("Wektory nie są tej samej długości\n");
    double result = 0.0;
    for(int i = 0; i<self.size();i++)
    {
         result += self[i] * other[i];
    }
    return result;
}

int main()
{
    try{
        std::vector<double> v{1,2,3};
        std::vector<double> w{4,9,2};
        double wyn = v * w;
        std::cout << wyn << "\n";
        std::cout << v * w << "\n";
    }
    catch(std::logic_error &e)
    {
        std::cout<<e.what()<<"\n";
    }
    return 0;
}