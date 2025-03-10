// S. Trowbridge 2024
#include <iostream>
#include <time.h>

void init(int *a, const int& SIZE) {
    for(int i=0; i<SIZE; ++i) { a[i] = rand() % 100 + 1; }
}

void print(int *a, const int& SIZE) {
    for(int i=0; i<SIZE; ++i) { std::cout << a[i] << " "; }
    std::cout << std::endl;
}

void sort(int *a, const int &SIZE) {      // selection sort - O(n^2)
    for(int i=0; i<SIZE-1; ++i) {         // iterate from first to second to last value
        int min = i;                      // assign min to current index
        print(a, SIZE);
        for(int j=i+1; j<SIZE; ++j) {     // iterate from i+1 to last index
            if(a[j] < a[min]) {           // find the minimum value from i+1 to last index
                min = j;
            }
        }
        if( min != i ) {                  // min index is not the current index: swap min value with current value
            std::swap(a[i], a[min]);
        }
    }
}

int main() {
    std::cout << std::endl;
    srand(time(NULL));

    const int SIZE = 5;
    int a[SIZE];

    std::cout << "Original: ";
    init(a, SIZE);
    print(a, SIZE);
    sort(a, SIZE);

    std::cout << "\nSorted: ";
    print(a, SIZE);

    std::cout << std::endl;
    return 0;
}
