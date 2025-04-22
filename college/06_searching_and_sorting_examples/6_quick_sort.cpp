// S. Trowbridge 2024
#include <iostream>
#include <time.h>

void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
/*
    Partition O(n)

    1. Assign pivot to the first value of the array. 
    2. move all values < pivot to the left of the pivot in the array (left subarray)
    3. move all values >= pivot to the right if the pivot in the array (right subarray)
    4. Return the middle index which separates the two subarrays as the pivot for the sort function.
*/
int partition(int *a, int start, int end)
{
    int pivot = a[start];                           // assign pivot to the first value
    int middle = start;                             // assign middle to the first index
    for(int i=start+1; i<=end; ++i) {               // iterate from second to last 
        if(a[i] < pivot) {                          // current < pivot: swap all values < pivot to the front of the array ( the left subarray )
            ++middle;                                    
            std::swap(a[i], a[middle]);                   
        }

    }
    std::swap(a[start], a[middle]);                 // swap the original pivot value into sorted position ( after all values < pivot )
    return middle;
}
/*
    Divide an array into two subarrays, then sort each subarray.
    Partition is an O(n) operation.
    Sort is a log(n) operation (recursively split an array into two subarrays, 1 becomes 2, becomes 4 becomes 8 etc.)
    For each sort function we do one partition function, therefore QuickSort algorithm has an O(n * log(n)) time complexity.
*/
void sort(int *a, int start, int end)
{
    if(start < end) {
        int pivotIndex = partition(a, start, end);       // determine the pivot point for the partition
        sort(a, start, pivotIndex - 1);                  // sort the left subarray
        sort(a, pivotIndex + 1, end);                    // sort the right subarray
    }
}

int main() {
    std::cout << std::endl;
    srand(time(NULL));

    const int SIZE = 6;
    int a[SIZE];

    std::cout << "Original:\t";
    for(int i=0; i<SIZE; ++i) { a[i] = rand() % 100 + 1; }
    print(a, SIZE);

    sort(a, 0, SIZE-1);

    std::cout << "\nSorted:\t\t";
    print(a, SIZE);

    std::cout << std::endl;
    return 0;
}
