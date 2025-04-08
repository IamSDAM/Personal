// S. Trowbridge 2023
#include <iostream>

class Number {
private:
    int num;    
public:
    Number(): num(0) {}
    Number(int i): num(i) {}

    Number& operator++() {                      // prefix overload ++c 
        ++num;                                  // modify the calling object
        return *this;                           // return the modified calling object
    }

    Number operator++(int) {                    // postfix overload c++
        Number temp{num};                       // make a copy of the calling object
        ++num;                                  // modify the calling object
        return temp;                            // return the copy (not incremented)
    }

    friend std::ostream& operator<<(std::ostream& out, const Number &c);
};

std::ostream& operator<<(std::ostream& out, const Number &c) {
    out << c.num;
    return out;
}

int main() {
    std::cout << std::endl;

    Number n(5);
    std::cout << "n:    " << n << std::endl;
    std::cout << "n++:  " << n++ << std::endl;  // postfix increment: std::cout << n then n=n+1
    std::cout << "n:    " << n << std::endl;
    std::cout << "++n:  " << ++n << std::endl;  // prefix increment: n=n+1 then std::cout << n

    std::cout << std::endl;
    return 0;
}