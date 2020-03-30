#include <iostream>
#include <chrono>

int main()
{
    unsigned int N = 200000;

    auto start1 = std::chrono::high_resolution_clock::now();
    for(unsigned int n = 1;n <= N; ++n)
    {
        int*p = new int[n];
        delete[] p;
    }
    auto finish1 = std::chrono::high_resolution_clock::now();
    std::cout<<"new/delete : "<< std::chrono::duration<double>(finish1-start1).count()<<" [s]\n";


    auto start2 = std::chrono::high_resolution_clock::now();
    for(unsigned int n = 1; n <= N; ++n)
    {}
    auto finish2 = std::chrono::high_resolution_clock::now();
    std::cout<<"++ : "<< std::chrono::duration<double>(finish2-start2).count()<<" [s]\n";
    return 0;
}
