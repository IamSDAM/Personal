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

void sort(int *a, int size) {             
    int v, index;                         
    for(int i=1; i<size; ++i) {      
        std::cout << "\n";     
        print(a, size);
        v = a[i];                         
        index = i;                        
        std::cout << "v:" << a[i] << " index: " << index << "\n";
        while(index>0 && a[index-1]>v) {  
            a[index] = a[index-1];        
            --index;                    
        }
        a[index] = v;    
        std::cout << "Store " << a[index] << " at index " << index << "\n";                 
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
