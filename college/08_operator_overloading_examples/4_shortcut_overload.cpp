// S. Trowbridge 2023
#include <iostream>

class Number {
private:
    double num;
public:
    Number(): Number(0) { }
    Number(double n): num(n) { }
    void output() const { std::cout << num << std::endl; }

    Number& operator+=(const Number &rhs) {     // binary shortcut overload
        num += rhs.num;                         // += in this statement adds a double
        return *this;                           // *this represents the calling object
    }
};

int main() {
    std::cout << std::endl;

    int x=5, y=10;
    std::cout << (x+=y) << "\n";                // expression resolves to a modified x (x = x + y)
    std::cout << x << "\n";                     // x is modified
    std::cout << y << "\n\n";                   // y is not

    Number a(3.5), b(2.0);

    //std::cout << (&a) << std::endl;           // commented statements show that the original object a is returned, not a copy
    (a+=b).output();                            // a is the calling object, b the parameter object, expression resolves to a modified a
    //std::cout << (&(a+=b)) << std::endl;
    //std::cout << (&a) << std::endl;

    std::cout << "\n";
    a.output();                                 // a is modified
    b.output();                                 // b is not
    std::cout << "\n";

    std::cout << std::endl;
    return 0;
}
