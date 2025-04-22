// S. Trowbridge 2024
#include <iostream>

/*
    summation(3, 0) 0+3
        summation(2, 3) 3+2
            summation(1, 5) base case: return 5+1
        summation(2, 3) return 6
    summation(3, 0) return 6
*/
int summation(int n, int sum=0)                 // tail recursive function: default argument (sum = 0)
{
    if(n==1) { return sum+1; }                  // base case: 
                                                //                  compute the final answer

    return summation(n-1, sum+n);               // recurisve task: 
                                                //                  compute current sum then pass sum to the next function call
}

int summationGoto(int n, int sum=0)             // tail recursion optimization: iterative equivalent of the tail recursive function using goto
{
    start:                                      // start the loop: start is a label for goto to jump to

    // similar to base case
    if(n==1) { return sum+1; }                  // end the loop: return sum + 1

    // similar to recursive task
    sum += n;                                   // compute current sum
    --n;                                        // reduce n by 1 

    goto start;                                 // repeat the loop: jump to start
}

int main() {
    std::cout << std::endl;

    int n = 3;

    std::cout << summation(n) << "\n";          // compute summation recursively with the default sum argument of 0
    std::cout << summation(n, 10) << "\n\n";    // compute summation recursively with a specified sum argument of 10

    std::cout << summationGoto(n) << "\n";      // compute summation iteratively using goto (similar to the compiler assembler method)

    std::cout << std::endl;
    return 0;
}