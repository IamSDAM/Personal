// S. Trowbridge 2024
#include <iostream>

int sum(int a, int b) { return a + b; }                 // original sum function
double sum(double a, double b) { return a + b; }        // overloaded with different parameter list
int sum(int a, int b, int c) { return a + b + c; }     // overloaded again with different parameter list

int main() {
    std::cout << std::endl;

    std::cout << sum(4, 5) << "\n";                     // call the first sum function

    std::cout << sum(4, 5, 6) << "\n";                  // call the third sum function
    
    std::cout << sum(4.5, 5.3) << "\n";                 // call the second sum function

    //std::cout << sum(4, 5.3) << "\n";                 // compiler error: ambigious function call

    std::cout << std::endl;
    return 0;
}//
