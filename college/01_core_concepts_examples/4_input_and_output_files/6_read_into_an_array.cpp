// S. Trowbridge 2024
#include <iostream>
#include <fstream>                                      
#include <sstream>                                      

void print(int *a, int size)            
{
    for(int i=0; i<size; ++i) {
        std::cout << a[i] << " ";
    }
}
void push_back(int *a, int capacity, int &size, int value)
{ 
    if(size == capacity) { return; }             
    a[size] = value;                    
    ++size;                             
}

int main( ) {
    std::cout << std::endl;

    const int CAPACITY = 100;                       // partially filled array of integers
    int a[CAPACITY];
    int size = 0; 

    std::ifstream file("data_1.csv");                                      
    std::string line;   

    while( std::getline(file, line) ) {             // read line of text from file into the variable line (repeat until out of lines)              
        std::string token;                                       
        std::stringstream parser(line);             // connect stringstream object to line (used to parse tokens)                          

        while( std::getline(parser, token, ',') ) { // extract token separated by commas from line (repeat until out of tokens) 
            int num = stoi(token);                  // convert token into integer
            push_back( a, CAPACITY, size, num );    // store integer into array
        }
    }

    file.close();                                           

    print(a, size);                                 // print the array

    std::cout << std::endl;
    return 0;
}
