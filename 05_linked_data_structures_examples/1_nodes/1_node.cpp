// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                           // data
    Node *next;                                         // link (a pointer to another node)
    Node(): data(0), next(nullptr) {}                   // default constructor 
    Node(const int &d): data(d), next(nullptr) {}       // parameterized constructor 
};

int main() {
    std::cout << std::endl;

    Node n1;                                            // instantiate two nodes
    Node n2{200};                                                

    std::cout << n1.data << "\t" << n1.next << "\n";    // print node data and link values                                                                                                                                          
    std::cout << n2.data << "\t" << n2.next << "\n";      

    std::cout << std::endl;
    return 0;
}
