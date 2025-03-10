// S. Trowbridge 2024
#include <iostream>
#include <time.h>
using namespace std;

void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
/*
    Split an array into two subarrays, then Merge the subararays into sorted order.
    Merge is an O(n) or linear operation.
*/
void merge(int *a, int start, int middle, int end) 
{
    int size = end - start + 1;             // number of values to be sorted
    int *temp = new int[size]{};

    int left = start;                       // first index of left subarray
    int right = middle + 1;                 // first index of right subarray
    int sorted = 0;                         // index of the sorted portion of the temporary array

    while(left <= middle && right <= end)   // while values exist in both subarrays
    {
        if( a[left] <= a[right]) {          // left value is smaller: 
            temp[sorted] = a[left];         //      stored left in sorted position
            ++left;                         //      move to next value in left subarray
        } else {                            // right value is smaller:
            temp[sorted] = a[right];        //      stored right in sorted position
            ++right;                        //      move to next value in right subarray
        }
        ++sorted;                           // advance index to next sorted position
    }
    while(left <= middle)                   // if left subarray was larger, sort its remaining values
    {
        temp[sorted] = a[left]; 
        ++left;
        ++sorted;
    }
    while(right <= end)                     // if right subarray was larger, sort its remaining values
    {
        temp[sorted] = a[right];
        ++right;
        ++sorted;
    }
    for(int i=0; i<size; ++i)               // copy the sorted temporary array back into the original array
    {
        a[start + i] = temp[i]; 
    }  
    delete [] temp;                         // delete the temporary array
}
/*
    Divide an array into size subarrays, then Merge the subarrays back into one sorted array.
    Merge is an O(n) operation.
    Sort is a log(n) operation (recursively split an array into two subarrays, 1 becomes 2, becomes 4 becomes 8 etc.)
    For each sort function we do one merge function, therefore the Merge Sort algorithm has an O(n * log(n)) time complexity.
*/
void sort(int *a, int start, int end) {     // separate the original array into numerous subarrays
    if(start < end) {   
        int middle = (start + end)/2;       // integer division (i.e. (0+5)/ 2 == 2 not 2.5)
        sort(a, start, middle);             // sort left subarray
        sort(a, middle + 1, end);           // sort right subarray
        merge(a, start, middle, end);       // merge the left and right subarrays
    } 
}

int main() {
    std::cout << endl;
    srand(time(NULL));

    const int SIZE = 8;
    int a[SIZE];

    std::cout << "Original: \t";
    for(int i=0; i<SIZE; ++i) { a[i] = rand() % 100 + 1; }
    print(a, SIZE);

    sort(a, 0, SIZE-1);

    std::cout << "\nSorted:\t\t";
    print(a, SIZE);

    std::cout << endl;
    return 0;
}
