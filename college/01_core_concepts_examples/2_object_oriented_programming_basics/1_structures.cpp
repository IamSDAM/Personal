// s. trowbridge 2024
#include <iostream>

struct Person                                   // user defined data type, structure named person
{
    std::string name;                                // name data member
    int age;                                    // age data member
};
void print(Person &p)                           // always pass objects by reference
{
    std::cout << p.name << " " << p.age << "\n";
}

int main() {
    std::cout << std::endl;

    Person p1;                                  // instantiate a Person object (similar to int x for creating an integer variable)
    p1.name = "John";                           // modify data member
    p1.age = 32;                                // modify data member

    Person p2;                                  // instantiate a second Person object 
    p2.name = "Jane";
    p2.age = 22;

    print(p1);                                  // pass object by reference
    print(p2);

    std::cout << std::endl;
    return 0;
}