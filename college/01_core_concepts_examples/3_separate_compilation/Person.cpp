// S. Trowbridge 2024

#include "Person.h"                                     // implementation files (.cpp) must include the related header file
                                                        // implementation files (.cpp) define class member and non-member functions

Person::Person(): name("noname"), age(0)                // member function requires scope resolution prefix before function name (Person::)    
{}                     
Person::Person(std::string n, int a): name(n), age(a) 
{}                                
std::string Person::getName() 
{ 
    return name; 
}      
int Person::getAge() 
{ 
    return age; 
}
void Person::setName(std::string n) 
{ 
    name = n; 
}   
void Person::setAge(int a) 
{ 
    age = a; 
}   

void print(Person &p)                                       // non-member function does not require scope resolution             
{
    std::cout << p.getName() << " " << p.getAge() << "\n";  
}