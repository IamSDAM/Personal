// S. Trowbridge 2024
#include <iostream>

class Color {
public:
    std::string name;
private:
    Color(): name("noname"){}
    std::string getName(){ return name; }   // inline definition
};

class Shape {
public:
    std::string name;
private:
    Shape();
    std::string getName();
};
Shape::Shape(): name("noname")              // out-of-line definitions
{
}
std::string Shape::getName()                // out-of-line definitions
{
    return name;
}

int main() {
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
