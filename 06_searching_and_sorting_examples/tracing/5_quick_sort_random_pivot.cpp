// S. Trowbridge 2023
#include <iostream>
#include <time.h>

const int PRINT_SORT = true;       // set true to trace sort function, false otherwise
const int PRINT_PART = false;       // set true to trace merge function, false otherwise

void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
void printRange(int *a, int start, int end) {
    for(int i=start; i<=end; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";    
}
int partition(int *a, int start, int end)
{
    int pivot = a[start];                           
    int middle = start;   

    if(PRINT_PART) { std::cout << "PARTITION:\tpivot = " << start << "\n"; }

    for(int i=start+1; i<=end; ++i) {               
        if(a[i] < pivot) {                          
            ++middle;                               
            std::swap(a[i], a[middle]); 
            if(PRINT_PART) { std::cout << "\t\t" << "swap: " << a[i] << " " << a[middle] << "\n"; }
        }
        if(PRINT_PART) { std::cout << "\t\t"; printRange(a, start, end); }      
    }

    std::swap(a[start], a[middle]);  

    if(PRINT_PART) { std::cout << "\n\t\t" << "swap: " << a[start] << " " << a[middle] << "\n\t\t"; printRange(a, start, end); std::cout << "\n"; }
     
    return middle;
}
int randomPivot(int *a, int start, int end) {
    srand(time(NULL));
    int r = start + rand() % (end-start+1);
    std::swap(a[r], a[start]);
    return partition(a, start, end);
}
void sort(int *a, int start, int end)
{
    
    if(start < end) {
        int pivot = randomPivot(a, start, end);     
        if(PRINT_SORT) { std::cout << "P: pivot = " << pivot << "\t"; printRange(a, start, end); }
    
        if(PRINT_SORT) { std::cout << "L: " << start << "-" << pivot-1 << "\n"; }
        sort(a, start, pivot - 1);

        if(PRINT_SORT) { std::cout << "R: " << pivot+1 << "-" << end << "\n"; }    
        sort(a, pivot + 1, end);
    }
    std::cout << "\n";
}
int main() {
    std::cout << std::endl;

    const int SIZE = 6;
    int a[SIZE] = {50, 20, 80, 30, 90, 10};

    std::cout << "Original:\t";
    print(a, SIZE);
    std::cout << "\n";

    sort(a, 0, SIZE-1);

    std::cout << "\nSorted:\t\t";
    print(a, SIZE);

    std::cout << std::endl;
    return 0;
}
