// S. Trowbridge 2024
#include <iostream>
using namespace std;                    // std is the global namespace

namespace et575                         // create an et575 namespace
{
    int x = 5;                          // int x is only accessible within the et575 namespace
}

namespace et580                         // create an et570 namespace
{
    char x = 'X';                       // char x is only accessible within the et580 namespace
}

int main() 
{
    cout << endl;

    {
        using namespace et575;          // et575 code block
        cout << x << endl;              // print x from et575
        cout << et580::x << endl;       // print x from et580
    }
    {
        using namespace et580;          // et580 code block
        cout << x << endl;              // print x from et580
        cout << et575::x << endl;       // print x from et575
    }

    cout << et575::x << endl;           // print x from et575 (this requires the scope resolution operator ::)
    cout << et580::x << endl;           // print x from et580 (this requires the scope resolution operator ::)

    cout << endl;
    return 0;
}
