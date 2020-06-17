#include <iostream>

using namespace std;

//#define N = 10;
//w define nie uzywa sie = oraz ;
#define N  10



#define KWADRAT(x) x*x
//ponizej znajduje sie poprawna definicja
#define KWADRAT2(x) (x*x)



//ponizej znajduje sie prawdopodobnie poprawna definicja, wczesniej nie mozna bylo przekazac wartosci ktora nie jest liczba, nie jestem pewien czy o taki blad chodzilo
#define PISZ(x) std::cout << #x << "= " << #x << "\n"

int main()
{
    cout<<N<<endl;
    cout<<KWADRAT(2)/KWADRAT(2)<<endl;
    // powinno być 1 a dostajemy wynik 4 poniewaz jest to rozwijane do postaci 2*2 / 2*2 co daje nam 2*2
    cout<<KWADRAT2(2)/KWADRAT2(2)<<endl;
    PISZ(3.2);
    PISZ(B);
    return 0;
}