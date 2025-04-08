// S. Trowbridge 2024
#include <iostream>

/*
    Fibonacci Sequence
    F(0) == 0
    F(1) == 1
    F(n) == F(n-1) + F(n-2) for n > 1

    n        = 0 1 2 3 4 5 6 7  8  9  10
    answer   = 0 1 1 2 3 5 8 13 21 34 55 ...

    Display the Recursion Tree of functions calls to compute fibonacci(4):

              f(4)                           3
            /      \                      /     \
        f(3)        f(2)                 2   +   1
       /    \      /    \               / \     / \
     f(2)   f(1) f(1)   f(0)           1 + 1   1 + 0
    /    \                            / \
  f(1)  f(0)                         1 + 0
*/ 
long fibonacci(int n)
{
    std::cout << n << "\n";
    if(n<2) { return n; }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    std::cout << std::endl;

    std::cout << fibonacci(4) << "\n\n";           

    std::cout << std::endl;
    return 0;
}