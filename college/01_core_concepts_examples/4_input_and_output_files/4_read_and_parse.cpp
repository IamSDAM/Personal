// S. Trowbridge 2024
#include <iostream>
#include <fstream> 
#include <sstream>                              // required for parsing and conversion

int main( ) {
    std::cout << std::endl;

    std::ifstream file("data_1.csv");                                   
    std::string line;

    while( getline(file, line) ) {              // read line of text from file into the variable line (repeat until out of lines)    
        std::string token;                          
        std::stringstream parser(line);         // connect stringstream object to line (used to parse tokens)   

        while( getline(parser, token, ',') ) {  // extract token separated by commas from line (repeat until out of tokens) 
            std::cout << token << "\n";         // print token
        }
    }

    file.close();                                   

    std::cout << std::endl;
    return 0;
}
