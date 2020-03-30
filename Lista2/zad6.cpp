#include <iostream> 

  
int main(int argc, char** argv) 
{ 
    //i zaczyna się od 1 bo na zerowej pozycji jest nazwa pliku np. a.out
    for (int i = 1; i < argc; i++) 
        std::cout << argv[i] << "\t"; 
  
    return 0; 
} 