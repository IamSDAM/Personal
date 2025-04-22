// S. Trowbridge 2020
#include <iostream>

class Number {
public:
    Number(): Number(0) { }
    Number(double n): num(n) { }
    void output() const { std::cout << num << "\n"; }

    Number operator-() const {          // unary member overload
        return Number(-num);            // return a negated temporary object
    }

private:
    double num;
};

int main() {
    std::cout << std::endl;

    int x = 5;
    std::cout << -x << "\n";             // x calls a negation function
    std::cout << x << "\n\n";            // integer negation resolves to a negated copy of x (original x does not change)

    Number n(3.25);
    (-n).output();                      // n calls a negation function, n is the calling object
    n.output();                         // negation of n resolves to a negated copy of n (original n does not change)

    std::cout << std::endl;
    return 0;
}
