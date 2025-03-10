// S. Trowbridge 2023
#include <iostream>
#include <time.h>

void init(int *a, const int& SIZE) {
    for(int i=0; i<SIZE; ++i) { a[i] = rand() % 100 + 1; }
}

void print(int *a, const int& SIZE) {
    for(int i=0; i<SIZE; ++i) { std::cout << a[i] << " "; }
    std::cout << std::endl;
}

void sort(int *a, const int &SIZE) {      
    for(int i=0; i<SIZE-1; ++i) {         
        int min = i;                      
        std::cout << "\n";
        print(a, SIZE);
        std::cout << "i: " << min << "\n";
        for(int j=i+1; j<SIZE; ++j) {     
            if(a[j] < a[min]) {           
                min = j;
                std::cout << "Find Min: " << min << "\n";
            }
        }
        if( min != i ) {                  
            std::swap(a[i], a[min]);
            std::cout << "Swap: " << a[i] << " " << a[min] << "\n";
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
