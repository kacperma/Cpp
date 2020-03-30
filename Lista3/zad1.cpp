#include <iostream>
#include <cstring>

void kopiuj(char* dokad, const char* skad)
{
    while(*dokad++ = *skad++)
    {
        continue;
    }
}

int main()
{
    char bufor[200];
    kopiuj(bufor,"Ala ma kota");
    std::cout<<"tekst "<<bufor<<" ma dlugosc "<<strlen(bufor)<<"\n";
    return 0;
}

/*              Zad1
1)  najwyższy priorytet ma operator ++
    najniższy priorytet ma operator =

2)  zwraca kolejny adres komórki (w tym przypadku)

3)  w przypadku deklaracji tworzona jest zmienna wskaźnikowa, moze rownież "wyłuskiwać" wartość pod danym wskaźnikiem

4)  zwraca referencje na to co znajduję się po lewej stronie równania

5)  wyrażenie warunkowe jest interpretowane w taki sposób że pętla jest wykonywana dopóki wartość logiczna jest prawdziwa (różna od 0)

*/