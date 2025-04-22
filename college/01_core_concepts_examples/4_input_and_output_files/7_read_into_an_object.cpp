// S. Trowbridge 2024
#include <iostream>
#include <fstream>                              
#include <sstream>                             

struct Person                                  
{
    std::string name;                                
    int age;                                   
};
void print(Person &p)   
{
    std::cout << p.name << " " << p.age << "\n";
}

int main( ) {
    std::cout << std::endl;

    std::ifstream file("data_2.csv");                               
    std::string line, temp;                     

    while( getline(file, line) ) {          // read line of text from file into the variable line (repeat until out of lines)               
        std::stringstream parser(line);         

        Person p;                           // create a person object
        getline(parser, p.name, ',');       // extract 1st token, store in person name
        getline(parser, temp, ',');         // extract 2md token, store in temp

        p.age = stoi(temp);                 // convert temp into integer, store in person age

        print(p);                           // print the person object
    }

    file.close();                                 

    std::cout << std::endl;
    return 0;
}
