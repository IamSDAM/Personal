// S. Trowbridge 2024
#include <iostream>

/*
    countDown(3)                print 3
        countDown(2)            print 2
            countDown(1)        print 1
                countDown(0)    return
            countDown(1)        return
        countDown(2)            return
    countDown(3)                return
*/
void countDown(int n)               // void recursive function
{
    if(n==0) { return; }            // base case: 
                                    //                  n == 0, stop printing

                                    // recursive task:  
    std::cout << n << std::endl;    //                  print each n as we countdown
    countDown(n-1);                 //                  count down to 0    
}

/*
    summation(3)  
        summation(2)  
            summation(1)    return 1
        summation(2)        return 1 + 2
    summation(3)            return 3 + 3
*/
int summation(int n)                // non-void recursive function
{ 
    if(n==1) { return 1; }          // base case: 
                                    //                  n == 1, return 1 to the previous function call   

                                    // recursive task:
    return summation(n-1) + n;      //                  count down from n to 1 to reach the base case, then sum 1 to n in reverse order
}

int main() {
    std::cout << std::endl;

    countDown(3);

    std::cout << std::endl << summation(3) << std::endl;  

    std::cout << std::endl;
    return 0;
}