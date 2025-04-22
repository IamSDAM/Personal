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
void sort(int *a, int size) {             // insertion sort algorithm - O(n^2)
    int v, index;                         // create value and index variables
    for(int i=1; i<size; ++i) {           // iterate from second to last value
        v = a[i];                         // backup current value
        index = i;                        // backup current index

        while(index>0 && a[index-1]>v) {  // right shift value into sorted position ( while previous > value and not the first value )
            a[index] = a[index-1];        //    right shift value at index
            --index;                      //    decrement index to previous position
        }

        a[index] = v;                     // insert original value at index
        print(a, size);
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
