// s. trowbridge 2024
#include <iostream>

class Person {
private:                        // external code cannot access private area
    std::string name;   
public:                         // external code can access public area
    int age;                                 
};

int main() {
    std::cout << std::endl;

    Person p1;                                  
    //p1.name = "John";        // compiler error: name is private                      
    p1.age = 32;                               

    std::cout << std::endl;
    return 0;
}