// S. Trowbridge 2024
#include <iostream>

class Shape {
private:
    std::string name;
    int size;
    static int numShapes;                               // static member
    static const int maxSize = 100;                     // static const member
public:
    Shape(): name("noname"), size(0)
    { 
        ++numShapes;                                    // increment numShapes
    }
    Shape(std::string n, int s): name(n) 
    {
        if(s > maxSize) {                               // if size exceeds maxSize limit size to maxSize      
            size = maxSize;      
        } else {
            size = s;
        }
        ++numShapes;                                    // increment numShapes
    }
    void print()                                        // instance member function
    {
        std::cout << name << " " 
                  << size << " " 
                  << numShapes << "\n"; 
    }   
    static int getNumShapes();                          // static member function
};

int Shape::numShapes = 0;                               // static variable should be initialized externally
int Shape::getNumShapes()                               // out-of-line static member function definition does not include the static keyword                       
{ 
    return numShapes; 
}   

int main() {
    std::cout << std::endl;

    Shape s1;
    Shape s2{"Circle", 50};
    Shape s3{"Square", 250};

    s1.print();
    s2.print();
    s3.print();
    std::cout << "\n";

    std::cout << Shape::getNumShapes() << "\n";         // classname used to call static data members
    std::cout << s1.getNumShapes() << "\n";             // object used to call static data members

    //std::cout << Shape::print() << "\n";              // compiler error: instance method cannot be called using static syntax (by the classname)

    std::cout << std::endl;
    return 0;
}
