// S. Trowbridge 2023
#include <iostream>

class Number {
private:
    double num;   
public:
    Number(): Number(0) { }
    Number(double n): num(n) { }
    double getNumber() const { return num; }                // required for non-member overload    
    void output() const { std::cout << num << std::endl; }

    Number operator+(const Number &rhs) const {             // binary arithmetic member overload
        return Number(num + rhs.num);                       // return a new object that is the "sum" of the calling and parameter object
    }
};

Number operator*(const Number &lhs, const Number &rhs) {    // binary arithmetic non-member overload
    return Number(lhs.getNumber() * rhs.getNumber());       // return a new object that is the "sum" of the parameter objects (requires accessors)
}

int main() {
    std::cout << std::endl;

    int x=5, y=10;
    std::cout << (x+y) << "\n";                             // neither x nor y is modified, a new value is returned
    std::cout << x << "\n";                                 
    std::cout << y << "\n";                                 
    std::cout << (x+y+x+x) << "\n\n";                       // operator chaining: neither x nor y is modified, a new value is returned
    
    Number a(3.5), b(2.0);

    (a+b).output();                                         // a is the calling object, b the parameter object, expression resolves to a new Number object
    (a+b+a+b).output();                                     // operator chaining: resolve one operation at a time
    std::cout << "\n";
    a.output();
    b.output();
    std::cout << "\n";

    (a*b).output();                                         // a is the first parameter object, b is the second parameter object

    std::cout << std::endl;
    return 0;
}
