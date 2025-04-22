// S. Trowbridge 2024
#include <iostream>
#include <sstream>                  // required for parsing and conversion

int main( ) {
    std::cout << std::endl;

                                                    // concept 1: convert a string into an integer, float, character
    std::string s1 = "5";
    int i = stoi(s1);                               // convert compatible string to integer

    std::string s2 = "5.05";
    float f = stof(s2);                             // convert compatible string to float

    std::string s3 = "A";
    char c = s3[0];                                 // copy first (and only) character of temp into a character variable

    std::cout << i << " " << f << " " << c << "\n";


                                                    // concepts 2: parse a string into tokens, convert tokens into integer, float, character
    std::string temp, line = "5,5.05,A";  
    std::stringstream parse(line);                  // connect stringstream to a string (for parsing)

    std::getline(parse, temp, ',');                 // read up until 1st comma and store into temp
    i = stoi(temp);                                 // convert temp into integer

    std::getline(parse, temp, ',');                 // read up until 2nd comma and store into temp
    f = stof(temp);                                 // convert temp into float

    std::getline(parse, temp, ',');                 // read up until end of string and store into temp
    c = temp[0];                                    // copy first (and only) character of temp into a character variable

    std::cout << i << " " << f << " " << c << "\n";
                                     
    std::cout << std::endl;
    return 0;
}
