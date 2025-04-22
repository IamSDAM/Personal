// S. Trowbridge 2024
#include <iostream>

int main() 
{
    std::cout << std::endl;
                                        // L-VALUE: any expression that resolves to an accessible memory address
    int a;                              // a variable
    std::string s;                      // a named object (not a temporary)
    const double d = 5;                 // a constant l-value

                                        // R-VALUE: any expression that isn't an L-VALUE
    5;                                  // a literal
    std::string();                      // a temporary object

                                        // L-VALUE REFERENCE
    int &b = a;                         // &b is an l-value reference
    const double &c = d;                // &c is a constant l-value reference

                                        // R-VALUE REFERENCE
    int &&e = 5;                        // &&e is a reference to a literal stored as a temporary object
    std::string &&g = std::string();    // &&g is a reference that can extend the lifetime of a temporary object

    std::cout << std::endl;
    return 0;
}
