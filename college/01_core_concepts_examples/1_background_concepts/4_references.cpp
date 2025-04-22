// S. Trowbridge 2024
#include <iostream>

int main() {
    std::cout << "\n";

    int i = 5;
    std::cout << i << " " << &i << "\n";        // the addressOf operator (&) returns the memory address of a variable

    int &r = i;                                 // r is a reference for i
    std::cout << i << " " << r << "\n";         // value of r == value of i

    std::cout << &i << " " << &r << "\n";       // memory address of r == memory address of i

    std::cout << "\n";    
    return 0;
}

