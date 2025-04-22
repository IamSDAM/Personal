// s. trowbridge 2024
#include <iostream>

class Person {
private:                                        
    std::string name; 
    int age;         
public:           
    Person(): name("noname"), age(0) {}                     // member functions (declared within the class)
    Person(std::string n, int a): name(n), age(a) {}                                
    std::string getName() { return name; }      
    int getAge() { return age; }
    void setName(std::string n) { name = n; }   
    void setAge(int a) { age = a; }         
};

void print(Person &p)                           
{
    std::cout << p.getName() << " " << p.getAge() << "\n";  // non-member function (declared outside of the class)
}

int main() {
    std::cout << std::endl;

    Person p1;     
    p1.setName("John");                                     // member function call (syntax: object.function() )   
    p1.setAge(32);   

    print(p1);                                              // non-member function call (syntax: function(object) )

    std::cout << std::endl;
    return 0;
}