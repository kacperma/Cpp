#include "random.h"
#include <iostream>
#include <ctime>
#include <cassert>
#include <climits>

Random::Random(int f1)
{
    assert( f1>0 && f1< INT_MAX);
    this->_fn=f1;
}

double Random::operator()()
{
    long long temp = this->_fn;
    temp = (16807*temp)%(INT_MAX);
    this->_fn=temp;
    double ret = double(temp)/double(INT_MAX-1);
    return ret;
}