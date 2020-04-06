#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>


int fibo1(int n)
{
    if((n==1)||(n==0)) {
        return(n);
    }else {
        return(fibo1(n-1)+fibo1(n-2));
    }
}

int fibo2(int n)
{
    return round( (1/sqrt(5)) * ( pow((2/( sqrt(5)-1 )),n) - pow((-2/( sqrt(5)+1 )),n)));
}

int fibo3(int n)
{
    static std::vector<int> static_fib;
    int temp = round( (1/sqrt(5)) * ( pow((2/( sqrt(5)-1 )),n) - pow((-2/( sqrt(5)+1 )),n)));
    static_fib.push_back(temp);
    return static_fib[n];
}

int main()
{
    //fibo1
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<=48;i++)
    {
        std::cout<<"fibo1_"<<i<<" = "<<fibo1(i)<<"\n";
    }
    auto finish1 = std::chrono::high_resolution_clock::now();
    

    //fibo2
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<=48;i++)
    {
        std::cout<<"fibo2_"<<i<<" = "<<fibo2(i)<<"\n";
    }
    auto finish2 = std::chrono::high_resolution_clock::now();
    
    
    //fibo3
    auto start3 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<=48;i++)
    {
        std::cout<<"fibo3_"<<i<<" = "<<fibo3(i)<<"\n";
    }
    auto finish3 = std::chrono::high_resolution_clock::now();
    
    //czas
    std::cout<<"\n\n";
    std::cout<<"fibo1 : "<< std::chrono::duration<double>(finish1-start1).count()<<" [s]\n";
    std::cout<<"fibo2 : "<< std::chrono::duration<double>(finish2-start2).count()<<" [s]\n";
    std::cout<<"fibo3 : "<< std::chrono::duration<double>(finish3-start3).count()<<" [s]\n";
    return 0;
}