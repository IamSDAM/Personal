// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                           
    Node *next;                                         
    Node(): data(0), next(nullptr) {}                   
    Node(const int &d): data(d), next(nullptr) {}       
};

void print(const Node &n) {                         // non-member function to print a Node object
    std::cout << n.data << " ";
}

int main() {
    std::cout << std::endl;

    Node n1{100};                                               
    Node n2{200};                                           
    Node n3{300};   
    Node n4{300};                                                     

    n1.next = &n2;                                  // link the nodes: n1 -> n2 -> n3 -> n4 -> nullptr
    n2.next = &n3;
    n3.next = &n4;

    /*
        The pointer p traversing the linked nodes:

            p
            n1  ->  n2  ->  n3  ->  n4  ->  nullptr
                    p
            n1  ->  n2  ->  n3  ->  n4  ->  nullptr   
                            p
            n1  ->  n2  ->  n3  ->  n4  ->  nullptr   
                                    p
            n1  ->  n2  ->  n3  ->  n4  ->  nullptr       
                                            p
            n1  ->  n2  ->  n3  ->  n4  ->  nullptr                         
    */
    Node *p = &n1;                                  // point p to the first linked node n1
    while( p != nullptr) {                          // advance temp through all of the linked nodes until it reaches the end
        print(*p);                                  // deference p to access the node it points to, then pass the node by reference to the print function
        p = p->next;                                // advance p to the next linked node
    }
    std::cout << "\n";    

    std::cout << std::endl;
    return 0;
}


