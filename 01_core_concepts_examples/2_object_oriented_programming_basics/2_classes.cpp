// s. trowbridge 2024
#include <iostream>

class Person {
public:                                             // external access requires a public access modifier
    std::string name;                           
    int age;                                    
};
void print(Person &p)                           
{
    std::cout << p.name << " " << p.age << "\n";
}

int main() {
    std::cout << std::endl;

    Person p1;                                  
    p1.name = "John";                           
    p1.age = 32;                               

    Person p2;                                   
    p2.name = "Jane";
    p2.age = 22;

    print(p1);                                  
    print(p2);

    std::cout << std::endl;
    return 0;
}