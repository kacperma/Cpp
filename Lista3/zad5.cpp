#include <iostream>
#include <string.h>

int main()
{
    char tmp[8];
    char haslo[8];
    strcpy(haslo,"Ta.jnE!");
    for(;;)
    {
        std::cout<<"podaj haslo: ";
        //char tmp[8];
        std::cin>>tmp;
        if(strcmp(tmp,haslo)==0)
            break;
        std::cout<<haslo<<"\n";
        std::cout<<"przykro mi, haslo jest niepoprawne!\n";
    }
    std::cout<<"witaj w systemie!\n";
    return 0;
}
//gdy długość "hasła" wpisywanego do tmp przekroczy długość 8 to prawdziwe hasło zostaje nadpisane resztą znaków
//                                                          np. qwertyuizxcvbnm
//                                                                     ^ i jest ósmym znakiem i reszta zxcvbnm staje się nowym hasłem
//                                                                       gdy następnie wpiszemy zxcvbnm to system nas wpuści
//aby program działał tak jak powinien to deklaracja tmp powinna znajdować się przed deklaracją hasla