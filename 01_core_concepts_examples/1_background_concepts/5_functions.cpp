// S. Trowbridge 2024
#include <iostream>

void print(int n)                  // pass by value: the value of i which was copied to n, int n =
{
    std::cout << n << "\n";   
}
void increment(int &n)             // pass by reference: similar to int &n = i
{
    ++n;                           // n and i are modified, because both names represent the same memory location
}

int main() {
    std::cout << std::endl;

    int i = 5;

    print(i);                       // the value of argument i is copied to parameter n      
    increment(i);                   // the memory address of argument i is coped to parameter n (n is another name for i)
    print(i);                       // i was modified by the increment function (due to pass by reference)

    std::cout << std::endl;
    return 0;
}
