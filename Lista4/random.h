#ifndef RANDOM_H
#define RANDOM_H
#include <ctime>
class Random
{
private:
    int _fn;
public:
    Random(int f1=time(0));
    double operator()();
};
#endif