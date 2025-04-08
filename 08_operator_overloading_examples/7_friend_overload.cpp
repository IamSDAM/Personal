// S. Trowbridge 2023
#include <iostream>

class Number {
private:
    double num;
public:
    Number(): Number(0) { }
    Number(double n): num(n) { }
    double getNumber() const { return num; }
    void setNumber(double n) { num = n; }
    void output() const { std::cout << num << std::endl; }

    friend Number operator*(const Number &lhs, const Number &rhs);  // declare a friend function (two parameters since friend is a non-member)
    friend bool operator>(const Number &lhs, const Number &rhs);    // declare a friend function (two parameters since friend is a non-member)
};

Number operator*(const Number &lhs, const Number &rhs) {
    return Number(lhs.num * rhs.num);                               // friend functions have direct access to data members
}
bool operator>(const Number &lhs, const Number &rhs) {
    return (lhs.num > rhs.num);                                     // friend functions have direct access to data members
}

int main() {
    std::cout << std::endl;

    Number a(3.5), b(2.0);

    (a*b).output();                                                 // a and b are parameter objects, neither are modified
    std::cout << (a>b) << std::endl;                                // a and b are parameter objects, neither are modified

    (a*b*a*b).output();                                             // operator chaining

    std::cout << std::endl;
    return 0;
}
