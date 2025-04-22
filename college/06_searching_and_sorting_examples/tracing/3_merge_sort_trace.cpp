// S. Trowbridge 2023
#include <iostream>

const int PRINT_SORT = true;       // set true to trace sort function, false otherwise
const int PRINT_MERGE = true;       // set true to trace merge function, false otherwise

void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
/*
    Merge 20 50 80 10 30 90  ( the final merge function call )

    W1: 0-2 3-5         ( 0-2 are the indicies for the left subarray, 3-5 are the indicies for the right subarray )
    10 0 0 0 0 0        ( values of the temporary array that we are sorting the left and right into )
    0-2 4-5             ( 4-5 because right was incremented from 3 to 4 since the right subarray had the smallest value (10) ) 
    10 20 0 0 0 0 
    1-2 4-5
    10 20 30 0 0 0 
    1-2 5-5
    10 20 30 50 0 0 
    2-2 5-5
    10 20 30 50 80 0    ( when the loop ends there is one remaining value to be sorted )
    3-2 5-5

    W2: 3-2             ( 3-2 are current values of left/middle indicating that the left subarray was completely sorted into temp )

    W3: 5-5             ( 5-5 are current values of right/end indicating that one last value in the right subarray must be sorted into temp )
    10 20 30 50 80 90 
    6-5
*/
void merge(int *a, int start, int middle, int end) 
{
    if(PRINT_MERGE) { std::cout << "\n\t\tMERGE: "; print(a, end-start+1); }   

    int size = end - start + 1;             
    int *temp = new int[size]{};

    int left = start;                       
    int right = middle + 1;                 
    int sorted = 0;                         

    if(PRINT_MERGE) { std::cout << "\n\t\tW1: " << left << "-" << middle << " " << right << "-" << end << "\n"; }   
    while(left <= middle && right <= end)   
    {
        if( a[left] <= a[right]) {          
            temp[sorted] = a[left];         
            ++left;  
            if(PRINT_MERGE) { std::cout << "\t\tL: "; print(temp, size); std::cout << "\t\t" << left << "-" << middle << " " << right << "-" << end << "\n"; }                    
        } else {                            
            temp[sorted] = a[right];        
            ++right; 
            if(PRINT_MERGE) { std::cout << "\t\tR: "; print(temp, size); std::cout << "\t\t" << left << "-" << middle << " " << right << "-" << end << "\n"; }                
        }
        ++sorted;   
    }

    if(PRINT_MERGE) { std::cout << "\n\t\tW2: " << left << "-" << middle << "\n"; } 
    while(left <= middle)  
    {
        temp[sorted] = a[left]; 
        ++left;
        ++sorted;
        if(PRINT_MERGE) { std::cout << "\t\tL: "; print(temp, size); std::cout << "\t\t" << left << "-" << middle << "\n"; }           
    }

    if(PRINT_MERGE) { std::cout << "\n\t\tW3: " << right << "-" << end << "\n"; } 
    while(right <= end)   
    {
        temp[sorted] = a[right];
        ++right;
        ++sorted;
        if(PRINT_MERGE) { std::cout << "\t\tR: "; print(temp, size); std::cout << "\t\t" << right << "-" << end << "\n"; }               
    }
    for(int i=0; i<size; ++i)  
    {
        a[start + i] = temp[i]; 
    }  
    print(temp, size); 
    std::cout << "\n";    
    delete [] temp;     
}
/*
    Sort 50 20 80 30 90 10 

    middle = 2                                                      ( (0+5)/2 integer division == 2 where 0 and 5 are the start and end indicies of the array )
    L: 0-2 (50 20 80)  -->  middle = 1                              ( 0-2 are the indicies of the left subarray with values 50 20 80, middle is the index of the middle value )
                            L: 0-1 (50 20)  -->     middle = 0
                                                    L: 0-0 (50)
                                                    R: 1-1 (20)      ( 1-1 are the indicies of the right subarray with value 20 )
                                                    M: 0-1 (20 50)   ( 0 1 are the indices of the subarray sent to the merge function, 20 50 are subarray values after merge )
                                            <-- 
                            R: 2-2 (80)
                            M: 0-2 (20 50 80) 
                    <--
    R: 3-5 (30 90 10)  -->  middle = 4
                            L: 3-4 (30 90)    -->   middle = 3
                                                    L: 3-3 (90)
                                                    R: 4-4 (90)
                                                    M: 3-4 (30 90)
                                            <--
                            R: 5-5 (10)
                            M: 3-5 (10 30 90)
                    <--
    M: 0-5 (10 20 30 50 80 90)
*/
void sort(int *a, int start, int end) {   
    if(PRINT_SORT) { std::cout << "RECURSE: "; print(a, end-start+1); }

    if(start < end) {   
        int middle = (start + end)/2;      
        if(PRINT_SORT) { std::cout << "middle = " << middle << "\n";  }                            
        if(PRINT_SORT) { std::cout << "L: " << start << "-" << middle << "\n";  }
        sort(a, start, middle);                                 
        if(PRINT_SORT) { std::cout << "R: " << middle+1 << "-" << end << "\n";   }        
        sort(a, middle + 1, end);                              
        if(PRINT_SORT) { std::cout << "M: " << start << "-" << end << "\n"; }
        merge(a, start, middle, end);                           
    }
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
