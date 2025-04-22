// S. Trowbridge 2023
#include <iostream>

class Set {
private:
    int values[5] = {10,20,30,40,50};           // c++11 member initialization: all Set objects will have an array with these values
public:
    void output() const {
        for(int i=0; i<5; ++i) { std::cout << values[i] << " "; }
        std::cout << "\n\n";
    }
    
    int& operator[](int index) {                // subscript member overload
        if(index < 0 || index > 4) { 
            throw std::out_of_range ("index is out of range"); 
        }   
        return values[index];                   // return the memory location of the variable at the specfied index                   
    }
 
    const int& operator[](int index) const {    // const return value cannot be modified in main, const member function cannot modify calling object
        if(index < 0 || index > 4) { 
            throw std::out_of_range ("index is out of range"); 
        }   
        return values[index];
    }
};

int main() {
    std::cout << std::endl;

    Set s1;                    
    s1.output();
    try {
        s1[0] = 100;                        // write to the variable in the values array at index 0
        s1[1] = 200;
        std::cout << s1[0] << "\n";         // read from the variable in the values array at index 0
        std::cout << s1[1] << "\n";
        std::cout << s1[2] << "\n";
        std::cout << s1[3] << "\n";
        std::cout << s1[4] << "\n\n";
    } catch(const std::out_of_range e) {
        std::cerr << e.what() << std::endl;
    }

    const Set s2;                           // instantiate a read-only Set object
    s2.output();
    try {
        //s2[0] = 500;                      // compiler error: read only object
        //s2[1] = 600;                      // compiler error: read only object
        std::cout << s2[0] << "\n";
        std::cout << s2[1] << "\n";
        std::cout << s2[2] << "\n";
        std::cout << s2[3] << "\n";
        std::cout << s2[4] << "\n";
    } catch(const std::out_of_range e) {
        std::cerr << e.what() << std::endl;
    }    

    std::cout << std::endl;
    return 0;
}
