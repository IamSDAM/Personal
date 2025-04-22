// s. trowbridge 2024
#include <iostream>

class Person {
private:                                        // external code cannot access private area
    std::string name; 
    int age;         
public:                                         // external code can access public area
    std::string getName() { return name; }      // accessor functions provide controlled read only access to private data members
    int getAge() { return age; }
    void setName(std::string n) { name = n; }   // mutator functions provide controlled modify access to private data members
    void setAge(int a) { age = a; }         
};

int main() {
    std::cout << std::endl;

    Person p1;                                  
    //p1.name = "John";                         // compiler error: name is private                      
    //p1.age = 32;                              // compiler error: age is private       
    p1.setName("John"); 
    p1.setAge(32);                            

    std::cout << std::endl;
    return 0;
}