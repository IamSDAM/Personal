// S. Trowbridge 2024
#ifndef PERSON_H                    // header files (.h) require header guard preprocessor directives (ifndef, define and endif statements)
#define PERSON_H

#include <iostream>                 // header files (.h) should include any and all libaries required for the included code to work

class Person {
private:                                        
    std::string name; 
    int age;         
public:           
    Person();                       // function declarations
    Person(std::string n, int a);                                
    std::string getName();    
    int getAge();
    void setName(std::string n);
    void setAge(int a);       
};

void print(Person &p);             // header files (.h) may declare relevant non-member functions that are specific to the class (or struct)

#endif