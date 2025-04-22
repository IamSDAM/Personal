// S. Trowbridge 2024
#include <iostream>
#include <fstream>                                  // required for ifstream/ofstream objects

int main( ) {
    std::cout << std::endl;

    std::ofstream file("blank.csv");                // open a file in the same directory 

    for(int i=1; i<=3; i++) {
        file << "Line " << i << " some text.\n";    // write a line of text
    }

    file.close();                                   // close the output file

    std::cout << std::endl;
    return 0;
}
