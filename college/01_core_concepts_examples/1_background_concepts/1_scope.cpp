// S. Trowbridge 2024
#include <iostream>
using namespace std;

int i = 0;                      // global variable

int main()                      // variable scope is where a variable NAME is accessible (defined by codeblocks)
{ 
    cout << i << "\n";          // print global i 

    int i = 5; 
    cout << i << "\n";          // print main i 

    {
        int i = 10;
        cout << i << "\n";      // print nested i
    }

    for(int i=0; i<10; ++i) {
        cout << i << " ";       // print for loop i
    }
    cout << "\n";

    cout << i << "\n";          // print main i          

    return 0;
}
