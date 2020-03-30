#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main()
{
    cout << setprecision(10);
    double ti = 1/sqrt(3.0);
    double pi = 0;
    for(int i = 0; i < 30; i++)
    {
        pi = 6 * pow(2,i) * ti;
        ti = (sqrt(pow(ti,2)+ 1) - 1)/ti;
        cout <<i<<"A: "<< pi << endl;
    }
    cout<<endl;
    //b
    ti = 1/sqrt(3.0);
    pi = 0;
    for(int i = 0; i < 30; i++)
    {
        pi = 6 * pow(2,i) * ti;
        ti = ti / (sqrt(pow(ti,2) + 1) + 1);
        cout <<i<<"B: "<< pi << endl;
    }

    return 0;
}
