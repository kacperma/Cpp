#include <iostream>
#include "ppmimage.h"

int main()
{
    PPMimage image("sample.ppm");
    image.zmiekcz();
    image.zapisz("nowy.ppm");
    return 0;
}