// S. Trowbridge 2023
#include <iostream>

class Number {
private:
    double num;    
public:
    Number(): Number(0) { }
    Number(double n): num(n) { }                                    // this constructor required for automatic type conversion to convert literal into object
    void output() const { std::cout << num << std::endl; }

    Number operator+(const Number &rhs) const {                     // binary arithmetic member overload (one calling object, one parameter object)
        return Number(num + rhs.num);
    }
    friend Number operator-(const Number &lhs, const Number &rhs);  // binary arithmetic friend overload (two parameter objects)
};

Number operator-(const Number &lhs, const Number &rhs) {            // friend binary arithmetic member overload 
    return Number(lhs.num - rhs.num);                               
}

int main() {
    std::cout << std::endl;

    Number a(3.5), b(2.0);
                                                                    // + is overloaded as member first operand calling object, second parameter object
    (a+5).output();                                                 // a is the calling object, 5 is converted into an parameter object, this works
    //(5+b).output();                                               // compiler error: 5 cannot be converted to a calling object, this does NOT work

                                                                    // - is overloaded as friend,  both operands are parameters
    (b-5).output();                                                 // b and 5 are parameters, b is auto converted into a parameter object, this works
    (5-b).output();                                                 // 5 and b are parameters, b is auto converted into a parameter object, this works
    std::cout << std::endl;
    return 0;
}
