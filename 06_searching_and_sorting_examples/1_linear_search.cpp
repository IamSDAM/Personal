// S. Trowbridge 2024
#include <iostream>

int getIndex(int *a, const int& SIZE, int value) {  // linear search - O(n)
    for(int i=0; i<SIZE; i++) {                     // iterate from 0 to size-1
        //std::cout << a[i] << "\n";
        if(a[i] == value) {                         // value is found: return the index of the value
            return i;
        }
    }
    return -1;                                      // value is not found
}

int main( ) {
    std::cout << std::endl;

    const int SIZE = 10;
    int numbers[SIZE] = {1, 5, 14, 23, 45, 52, 58, 71, 82, 91};

    for(int i=0; i<SIZE; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Number 23 is located at index " << getIndex(numbers, SIZE, 23) << "\n\n";
    std::cout << "Number 58 is located at index " << getIndex(numbers, SIZE, 58) << "\n\n";
    std::cout << "Number 11 is located at index " << getIndex(numbers, SIZE, 11) << "\n\n";

    std::cout << std::endl;
    return 0;
}
