#include <iostream>

int nwd(int x, int y)
{
    //trzeba zmienić and na or, gdy tylko jeden z nich będzie 0 to program będzie się zapętlać
    if(x == 0 or y == 0) return -1;

    x = std::abs(x);
    y = std::abs(y);

    while (x != y)
    {
        if(x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
    return x;
}

int main()
{
    std::cout << nwd(132,0) << "\n";
    return 0;
}
