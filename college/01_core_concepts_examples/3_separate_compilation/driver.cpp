// S. Trowbridge 2024
#include <iostream>                                             // driver programs should include any relevant class files and libraries for the included code to work
#include "Person.h"

int main()                                                      // driver programs should test ALL functions and types created in the program
{
    std::cout << std::endl;  

    Person p1;                                                  // test default constructor
    p1.setName("John");                                         // test mutators
    p1.setAge(32);

    std::cout << p1.getName() << " " << p1.getAge() << "\n";    // test accessors

    Person p2{"Jane", 25};                                      // test parameterized constructor

    print(p2);                                                  // test print
    
    std::cout << std::endl;
    return 0;
}