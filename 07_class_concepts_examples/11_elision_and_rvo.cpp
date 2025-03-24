// S. Trowbridge 2023
#include <iostream>

class Shape {
private:
    int size;
public:
    Shape(): size(0) 
    {
        std::cout << "default constructor\n";
    }
    Shape(const Shape &s): size(s.size)
    {
        std::cout << "copy constructor\n";
    }    
    Shape& operator=(const Shape &s) 
    {
        std::cout << "assignment overload\n";        
        this->size = s.size;
        return *this;
    }

};

void passByValue(Shape c)                           // pass by value
{ 
}
Shape returnByValue()                              // return by value
{
    Shape s;
    return s;
}

int main() {
    std::cout << std::endl;

    std::cout << "CONSTUCT OBJECTS:\n";

    Shape s1{};                                    // call the default constructor
    Shape s2 = s1;                                 // call the copy constructor
    Shape s3 = Shape{};                            // call the default constructor instead of copy constructor (copy elision optimization for temporary objects)
    std::cout << "\n\n"; 

    std::cout << "PASS BY VALUE:\n";
    passByValue(s1);                                // call the copy constructor
    passByValue( Shape{} );                         // call the default constructor instead of copy constructor (copy elision optimization for temporary objects)
    std::cout << "\n\n"; 

    std::cout << "RETURN BY VALUE:\n";
    s3 = returnByValue();                           // call the default constructor, then assignment overload to copy returned temporary object
    Shape c4 = returnByValue();                     // call the default constructor (return value optimization for temporary objects)

    std::cout << std::endl;
    return 0;
}
