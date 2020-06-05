#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;

auto convert(char *in) {
    int result;
    stringstream str(in);
    str >> result;
    return result;
}

int main()
{
    char * tabl = " 1201";
    cout << convert(tabl)/2;//powinno być 600
    return 0;
}
