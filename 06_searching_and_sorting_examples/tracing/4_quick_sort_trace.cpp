// S. Trowbridge 2023
#include <iostream>

const int PRINT_SORT = true;       // set true to trace sort function, false otherwise
const int PRINT_PART = true;       // set true to trace merge function, false otherwise

void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
void printRange(int *a, int start, int end) {
    for(int i=start; i<=end; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";    
}
/*
    Partition 50 20 80 30 90 10 ( first partition function call )

    p = 50                  assign pivot to first value
    m = s = 0               assign middle to start which is the first index

    50 20 80 30 90 10
    p  i
    m
       m                    a[i] < a[p]: ++m, swap(a[m], a[i])
    50 20 80 30 90 10
    p  m  i                
    50 20 80 30 90 10
    p  m     i
          m                 a[i] < a[p]: ++m, swap(a[m], a[i])
    50 20 30 80 90 10
    p     m     i           
    50 20 30 80 90 10
    p     m        i
             m              a[i] < a[p]: ++m, swap(a[m], a[i]), loop ends
    50 20 30 10 90 80    
    s        m              swap( a[s], a[m] )

    10 20 30 50 90 80

    return 3                return m
*/
int partition(int *a, int start, int end)
{
    int pivot = a[start];                           
    int middle = start;   

    if(PRINT_PART) { std::cout << "PARTITION:\tpivot = " << start << "\n"; }

    for(int i=start+1; i<=end; ++i) {               
        if(a[i] < pivot) {                          
            ++middle;                               
            std::swap(a[i], a[middle]); 
            if(PRINT_PART) { std::cout << "\t\t" << "1st swap: " << a[i] << " " << a[middle] << "\n"; }
        }
        if(PRINT_PART) { std::cout << "\t\t"; printRange(a, start, end); }      
    }

    std::swap(a[start], a[middle]);  

    if(PRINT_PART) { std::cout << "\n\t\t" << "2nd swap: " << a[start] << " " << a[middle] << "\n\t\t"; printRange(a, start, end); std::cout << "\n"; }
     
    return middle;
}
/*
    Sort 50 20 80 30 90 10

    P: pivot = 3 (10 20 30 50 90 80)                                                            partition returns pivot of 3, array is (10 20 30 50 90 80)
    L: 0-2 (10 20 30)               --> P: pivot = 0 (10 20 30)                            
                                        L: 0- -1 ()                                             start not < end, do nothing
                                        R: 1-2 (20 30)          --> P: pivot = 1 (20 30)
                                                                    L: 1-0 ()
                                                                    R: 2-2 (30)
                                                                <--
                                    <--
    R: 4-5 (90 80)                  --> P: pivot = 5 (80 90)
                                        L: 4-4 (80)
                                        R: 6-5 ()
                                    <--
    <--
*/
void sort(int *a, int start, int end)
{
    
    if(start < end) {
        int pivot = partition(a, start, end);  
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
