// S. Trowbridge 2024
#include <iostream>

class Shape {
private:
    std::string name;
public:
    Shape(): name("noname") {}
    Shape(std::string n): name(n) {}
    std::string getName() const { return name; } 
};

Shape f1() {                                  
    Shape s{"Circle"};                     
    return s;                                   // automatic variable s is destroyed, a temporary copy is returned
}

int main() {
    std::cout << std::endl;

    Shape();                                    // instantiate a temporary object

    f1();                                       // resolves to a temporay object

    Shape s1 = f1();                            // s1 is constructed from a temporary object

    std::cout << s1.getName() << std::endl;     // s1 has the same value as s

    std::cout << std::endl;
    return 0;
}
