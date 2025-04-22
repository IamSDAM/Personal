// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;
    Node *prev;                                 // prev pointer to access node before the current node
    Node(): data(0), next(nullptr), prev(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr), prev(nullptr) {}                                
};
/*
    Doubly Linked List

            head                                        tail
                \                                       /
    nullptr <- node <-> node <-> node <-> node ->  nullptr

*/
struct List {                                               
    Node *head;                                 // pointer to the first node                                              
    Node *tail;                                 // pointer to the last node
    List(): head(nullptr), tail(nullptr) {}     // constructor: construct an empty list
    ~List()                                     // destructor: safe deletion of all nodes in the stack
    {
        Node *n = head;                         // point n to the first node
        Node *backup = nullptr;
        while(n != nullptr) {                   // advance n through all nodes in the list
            backup = n;                         // point backup to node n
            n = n->next;                        // advance n to the next node
            delete backup;                      // delete the backup node
        }
    }                  
};

// Return true if the list is empty, false otherwise
bool empty(List &list)                          
{
    if(list.head == nullptr) {                      
        return true;
    } else {
        return false;
    }
}
// Return a reference to the data inside the first node
int& front(List &list) {
    return list.head->data;
}
// Return a reference to the data inside the last node
int& back(List &list) {
    return list.tail->data;
}
// Add a node to the front of the list   
void push_front(List &list, const int &d)            
{
    Node *n = new Node(d);                      // point n to a new node 
    if( empty(list) ) {                         // if list is empty, make n the first and last node
        list.head = list.tail = n;
    } else {
        n->next = list.head;                    // link n forward to the first node:    n  -> first
        list.head->prev = n;                    // link first node back to n:           n <-> first
        list.head = n;                          // n becomes the new first node
    }
}
// Add a node to the back of the list 
void push_back(List &list, const int &d)                               
{
    if( empty(list) ) {                         // if list is empty: push_front and exit
        push_front(list, d);
        return;
    }
    
    Node *n = new Node(d);                      // point n to new node
    n->prev = list.tail;                        // link n backwards to the last node:       last <- n
    list.tail->next = n;                        // link last forward to n:                  last <-> n                     
    list.tail = n;                              // n becomes the new last node
}
// Remove the first node in the list
void pop_front(List &list)                      
{
    if( empty(list) ) {                         // if list is empty, exit
        return; 
    }

    Node *n = list.head;                        // point n to the first node
    list.head = list.head->next;                // second node becomes the new first node

    if(list.head == nullptr) {                  // if list will be empty, reset tail
        list.tail = nullptr;
    } else {
        list.head->prev = nullptr;              // if list will have data, link first node backwards to nullptr
    }

    delete n;                                   // delete the original first node 
}
// Remove the last node in the list
void pop_back(List &list)
{
    if( empty(list) ) {                         // if list is empty, exit
        return;
    }

    Node *n = list.tail;                        // point n to the last node

    list.tail = list.tail->prev;                // point tail to the second to last node

    if(list.tail == nullptr) {                  // if list will be empty, reset head
        list.head = nullptr;
    } else {                                    // if list will have data, link new tail forwards to nullptr
        list.tail->next = nullptr;
    }

    delete n;                                   // remove the original last node
}
// Add a node before node t in the list
// If successful, return a pointer to the new node, otherwise return a pointer to the t node
Node* insert(List &list, Node *t, const int &d)
{   
    if( empty(list) || t == nullptr ) {         // if list is empty or t invalid, exit and return the pointer to node t       
        return t;                                
    }
 
    Node *n = new Node(d);                      // point n to a new node
    n->next = t;                                // link n forwards to the node after t:           n  -> t
    n->prev = t->prev;                          // link n backwards to node t:              p <-  n  -> t
    t->prev = n;                                // link t backwards to node n:              p <-  n <-> t

    if(n->prev == nullptr) {                    // if n is first node, point head to n
        list.head = n;
    } else {                                    // if n is not the first node,
        n->prev->next = n;                      // link previous node forward to n          p <-> n <-> t
    }

    return n;                                   // return a pointer to the newly inserted node
}
// Remove the node t from the list
// If successful, return a pointer to the node after the erased node, if this is the end of list return nullptr
// If unsuccesful, return a pointer to node t
Node* erase(List &list, Node *t)
{
    if( empty(list) || t == nullptr ) {
        return t;                               // if list is empty, t invalid or t is the end of list, exit, return pointer to node t   
    } else if( t == list.head) {                // if t is first node, pop_front, return new first node
        pop_front(list);
        return list.head;
    } else if( t == list.tail ) {               // if t is last node, pop_back, return nullptr
        pop_back(list);
        return nullptr;
    }

    Node *n = t->next;                          // point n to node after t:                         b <-> t <-> a
    t->prev->next = t->next;                    // link node before t forwards to node after t:     b  -> a
    t->next->prev = t->prev;                    // link node after t backwards to node before t:    b <-> a
    
    delete t;                                   // remove the node t

    return n;                                   // return the node after t
}
// Print a list in forward order
void print(const List &list) {                              
    Node *n = list.head;                        // point n to the first node                                       
    while(n != nullptr) {                       // advance n forwards through all nodes in list        
        std::cout << n->data << " ";            // print the data of node n   
        n = n->next;                            // point n to the next node
    }
    std::cout << "\n";
}
// Print a list in reverse order
void printRev(const List &list) {                              
    Node *n = list.tail;                        // point n to the last node                                       
    while(n != nullptr) {                       // advance n backwards through all nodes in list  
        std::cout << n->data << " ";            // print the data of node n   
        n = n->prev;                            // point n to the previous node
    }
    std::cout << "\n";
}
// Copy one list to another list
void duplicate(const List &a, List &b)
{
    Node *n = a.head;                           // point n to the first node in list A
    while(n != nullptr) {                       // advance n through all nodes in list A until it reaches the end
        push_back(b, n->data);                  // copy the data from node n in list A into list B
        n = n->next;                            // point n to the next node in list A
    }    
}
// Determine if the value d is in the list. If so, return a pointer to the node that stores it, otherwise return nullptr
Node* find(const List &list, int d) {
    Node *n = list.head;                        // point n to the first node                                                                     
    while(n != nullptr) {                       // advance n through all nodes in list                                                      
        if(n->data == d) { return n; }          // if node n stores the equivalent of d, return a pointer to node n      
        n = n->next;                            // point n to the next node
    }
    return nullptr;                             // if data was not found, return nullptr
}


int main() {
    std::cout << std::endl;

    List list; 

    std::cout << "PUSH FRONT/BACK\n";           // test push front/back
    push_front(list, 400);
    push_front(list, 200);  
    push_front(list, 100);
    push_back(list, 600);  
    push_back(list, 800); 
    push_back(list,1000);
    push_back(list,1200); 

    print(list);                                // test forward and reverse traversal
    printRev(list);

    std::cout << "\nPOP FRONT/BACK\n";          // test pop front/back
    pop_front(list);
    pop_back(list);
    pop_back(list);
    print(list);
    printRev(list); 

    Node *n = nullptr;                          // create a node pointer

    std::cout << "\nFRONT/BACK\n";              // test front/back
    std::cout << front(list) << "\n";       
    std::cout << back(list) << "\n";
    print(list); 
    printRev(list);   

    std::cout << "\nFIND/INSERT\n";             // test find and insert 
    n = find(list, 200);
    std::cout << "Insert 100 before " 
              << n->data << "\n";               // test return value    
    n = insert(list,n, 100);                    // insert 100 before 200 (edge case)
    std::cout << "Returned Iterator: " 
              << n->data << "\n";               // test return value
    n = find(list, 400);   
    n = insert(list, n, 300);                   // insert 300 before 400  (middle case)    
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";              // test erase and insert 
    n = find(list, 100);
    std::cout << "Erase 100 " << "\n";        
    n = erase(list, n);                         // erase 100 (edge case)
    std::cout << "Returned Iterator: " 
              << n->data << "\n";               // test return value
    n = find(list, 300);   
    n = erase(list, n);                         // erase 300 (middle case)  
    n = find(list, 800);   
    n = erase(list, n);                         // erase 800 (edge case)  
    print(list);
    printRev(list);   

    std::cout << "\nCOPY\n";                    // test duplicate
    List list_copy;
    duplicate(list, list_copy);                 // duplicate list without sharing memory
    n = find(list, 200);                        // erase a node to modify the original list
    erase(list, n);                              
    print(list);
    print(list_copy);                           // test if the copy contains the original data to check for distinct memory allocation                    

    std::cout << std::endl;
    return 0;
}