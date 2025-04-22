// S. Trowbridge 2024
#include <iostream>
#include <sstream>                          // required for parsing and conversion

int main( ) {
    std::cout << std::endl;

    std::string line = "This,is,a,string";  // comma delimited text string
    std::string token;                      // varieble to store each token of data

    std::stringstream parse(line);          // connect stringstream to a string

    while( getline(parse, token, ',') ) {   // while data remains: read string up until comma and store into token
        std::cout << token << "\n";         // print token
    }
                     
    std::cout << std::endl;
    return 0;
}