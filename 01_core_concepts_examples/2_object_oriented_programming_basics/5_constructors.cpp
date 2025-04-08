// s. trowbridge 2024
#include <iostream>

class Person {
private:                                        
    std::string name; 
    int age;         
public:           
    Person(): name("noname"), age(0) {}                 // default constructor initializes an object with default values
    Person(std::string n, int a): name(n), age(a) {}    // parameterized constructor initializes an object with values specified by parameter                              
    std::string getName() { return name; }      
    int getAge() { return age; }
    void setName(std::string n) { name = n; }   
    void setAge(int a) { age = a; }         
};
void print(Person &p)                           
{
    std::cout << p.getName() << " " << p.getAge() << "\n";  // external print function requires accessor functions to access private data
}

int main() {
    std::cout << std::endl;

    Person p1;                                          // call the default constructor                                  
    print(p1);

    Person p2{"John", 32};                              // call the parameterized constructor (arguments match the parameters)
    print(p2);           

    std::cout << std::endl;
    return 0;
}