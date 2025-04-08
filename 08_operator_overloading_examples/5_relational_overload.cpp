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

    bool operator==(const Number &rhs) const {              // binary relational member overload (one parameter)
        return num == rhs.num;                              // return true or false
    }
};

bool operator>(const Number &lhs, const Number &rhs) {      // binary relational non-member overload (two parameters)
    return ( lhs.getNumber() > rhs.getNumber() );           // non-member variant does not have direct access to data members, requires accessors 
}

int main() {
    std::cout << std::endl;

    Number a(3.5), b(2.0), c(3.25);

    std::cout << (a==b) << std::endl;       // a is the calling object, b is the parameter object, neither are modified
    std::cout << (a>b) << std::endl;        // a is the first parameter object, b is the second parameter object, neither are modified

    std::cout << "\n";
    a.output();
    b.output();
    c.output();
    std::cout << "\n";

    std::cout << (a==b) << std::endl;       // a==b compares objects, == operator must be overloaded for Number        
    std::cout << (&a==&a) << std::endl;     // &a==&a compares memory address, == overload not needed

    std::cout << std::endl;
    return 0;
}
