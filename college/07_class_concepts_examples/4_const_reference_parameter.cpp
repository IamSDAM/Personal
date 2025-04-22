// S. Trowbridge 2024
#include <iostream>

class Shape {
private:
    std::string name;
public:
    Shape(): name("Circle") {}
    std::string getName() const { return name; } 
    void print() { std::cout << name << "\n"; }

    void setName(const std::string &n) {            // const reference parameter
        //n = "Square";                             // compiler error: the parameter n cannot be modified
        name = n;       
    }
};

int main() {
    std::cout << std::endl;

    Shape s;
    s.setName("Square");
    s.print();

    std::cout << std::endl;
    return 0;
}
