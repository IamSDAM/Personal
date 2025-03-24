// S. Trowbridge 2024
#include <iostream>

class Shape {
private:
    std::string name;
public:
    Shape(): name("noname") {}
    std::string getName() const { return name; }        // const member function: calling object cannot be modified
    void print() const { std::cout << name << "\n"; }   // const member function: calling object cannot be modified
/*
    void setName(std::string n) const {
        name = n;                                       // compiler error: const member function attempts to modify the calling object
    }
*/
};

int main() {
    std::cout << std::endl;

    Shape s;
    //s.setName("Circle");
    std::cout << s.getName() << "\n";
    s.print();

    std::cout << std::endl;
    return 0;
}
