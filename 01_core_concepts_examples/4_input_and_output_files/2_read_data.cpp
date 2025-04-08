// S. Trowbridge 2024
#include <iostream>
#include <fstream>                      // required for ifstream/ofstream objects

int main( ) {
    std::cout << std::endl;

    std::ifstream file("data_1.csv");     // open a file in the same directory                    
    std::string line;                          

    while( getline(file, line) ) {      // read line of text from file into the variable line (repeat until out of lines)  
        std::cout << line << "\n";      // print line
    }

    file.close();                       // close the file      

    std::cout << std::endl;
    return 0;
}
