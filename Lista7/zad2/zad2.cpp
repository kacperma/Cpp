#include <iostream>
#include "ppmimage.h"

int main()
{
    PPMimage image("sample.ppm");
    //image.znieksztalc(20,50);
    image.zapiszpgm("nowy.ppm");
    return 0;
}