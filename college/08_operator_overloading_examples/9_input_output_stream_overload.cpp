// S. Trowbridge 2023
#include <iostream>

class Number {
public:
    Number(): Number(0) { }
    Number(double n): num(n) { }
    double getNumber() const { return num; }
    void setNumber(double n) { num = n; }
    void output() const { std::cout << num << std::endl; }

    friend std::ostream& operator <<(std::ostream &out, const Number &n);   // friend overloads, two parameters
    friend std::istream& operator >>(std::istream &in, Number &n);          // friend overloads, two parameters

private:
    double num;
};

std::ostream& operator<<(std::ostream &out, const Number &n) {              // out object is updated to include data from object n
    out << n.num;                                                           // output data from object data member
    return out;
}
std::istream& operator>>(std::istream &in, Number &n) {                     // in object is updated as data is removed and stored into object n
    in >> n.num;                                                            // store data into object data member
    return in;
}

int main() {
    std::cout << std::endl;

    Number a(3.3), b(2.25);
    std::cout << a << " " << b << std::endl;                               

    Number c;
    std::cout << "\nEnter two numbers: ";
    std::cin >> b >> c;                                                      // assign data to object b and c
    std::cout << a << " " << b << " " << c << std::endl;

    std::cout << std::endl;
    return 0;
}
