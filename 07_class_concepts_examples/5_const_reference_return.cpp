// S. Trowbridge 2024
#include <iostream>

class Shape {
private:
    int size;
public:
    Shape(): size(0) {}
    const int& getSize() {      // return by const reference: the returned reference cannot be used to modify the original variable
        return size;
    }
};

int main() {
    std::cout << std::endl;

    Shape s;

    int x = s.getSize();        // ok - this copies the value of size to x (x is a duplicate)
    ++x;

    //int &y = s.getSize();     // compiler error: this attempts to create a reference to size, but that would enable modification of size

    std::cout << std::endl;
    return 0;
}
