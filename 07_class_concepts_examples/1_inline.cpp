// S. Trowbridge 2023
#include <iostream>

inline void print(int a[], int size)  {    // inline function
    for(int i=0; i<size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

    const int SIZE = 5;
    int a[SIZE] = {1,2,3,4,5};

    print(a, SIZE);                        // the compiler will replace the function call with the function code

    std::cout << std::endl;
    return 0;
}
