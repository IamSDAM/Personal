
/*Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false; 
            int copy = x;
            long long reversed = 0;
    
            while (x > 0) {
                int lastDigit = x % 10;       
                reversed = reversed * 10 + lastDigit; 
                x /= 10;
            }
    
            return copy == reversed;
        }
    };
int main() {
    Solution sol;

    int test1 = 121;
    cout << "Is " << test1 << " a palindrome? " 
         << boolalpha << sol.isPalindrome(test1) << endl;

    int test2 = -121;
    cout << "Is " << test2 << " a palindrome? " 
         << boolalpha << sol.isPalindrome(test2) << endl;

    int test3 = 10;
    cout << "Is " << test3 << " a palindrome? " 
         << boolalpha << sol.isPalindrome(test3) << endl;

    int test4 = 1234567899;
    cout << "Is " << test4 << " a palindrome? " 
         << boolalpha << sol.isPalindrome(test4) << endl;

    int test5 = 1221;
    cout << "Is " << test5 << " a palindrome? " 
         << boolalpha << sol.isPalindrome(test5) << endl;

    return 0;
}
