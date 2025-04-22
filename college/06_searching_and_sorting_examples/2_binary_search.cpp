// S. Trowbridge 2024
#include <iostream>

int getIndex(int *a, int size, int n) { // binary search - O(log n)
    int start = 0, end = size-1;        // start - first value in an array, end - the last value in an array
    while(start <= end) {               // repetitively halve the search zone
        int middle = (start+end)/2;     // find middle of search zone
        //std::cout << start << " " << middle << " " << end << "\n"; // enable to view the process

        if(a[middle] == n) {            // middle is value: return the index of middle
            return middle;
        }
        else if(a[middle] < n) {        // middle less than value: point start to middle index + 1 (halves the search zone)
            start = middle+1;           
        }
        else {                          // middle less than value: point end to middle index - 1 (halves the search zone)
            end = middle-1;             
        }
    }
    return -1;                          // value was not found
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
