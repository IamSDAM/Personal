// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data ;                                                  
    Node *next;
    Node *prev; 
    Node(): data(0), next(nullptr), prev(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr), prev(nullptr) {}                                
};

/*
    Doubly Linked List

    head                                             tail
        \                                           /
    nullptr <- node <-> node <-> node <-> node ->  nullptr
    |
    Iterator
*/
struct Iterator {
    Node *current;                              // target node
    Iterator(Node *n): current(n) {             // point iterator to specific node
    }
    void next() {                               // advance iterator to next node
        current = current->next;
    }
    void prev() {                               // advance iterator to previous node
        current = current->prev;
    }
    bool hasNext() {                            // return true if current is a valid node (not nullptr), false otherwise
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }
    bool hasPrev() {                            // return true if current is a valid node (not nullptr), false otherwise
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }    
    int& getData() {                            // return a reference to the data stored in the current node
        return current->data;
    }
};

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
    Iterator begin() {                          // return an iterator pointing to the first node (for forward traversal)
        return Iterator(head);
    } 
    Iterator end() {                            // return an iterator to the value past the end of the list (nullptr)
        return Iterator(nullptr);
    }
    Iterator rbegin() {                         // return an iterator pointing to the tail node (for reverse traversal)
        return Iterator(tail);
    }                    
    Iterator rend() {                           // return an iterator to the value past the start of the list (nullptr)
        return Iterator(nullptr);
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
// Add a new node before a specified node in the list
// If successful, return an iterator to the new node, otherwise return the original iterator
Iterator insert(List &list, Iterator it, const int &d)
{   
    if( empty(list) || it.current == nullptr ) {// if list is empty or iterator invalid, exit and return the original iterator       
        return it;                                
    }
 
    Node *n = new Node(d);                      // point n to a new node
    n->next = it.current;                       // link n forwards to the node after iterator:        n  -> it
    n->prev = it.current->prev;                 // link n backwards to iterator:                p <-  n  -> it
    it.current->prev = n;                       // link iterator backwards to node n:           p <-  n <-> it

    if(n->prev == nullptr) {                    // if n is first node, point head to n
        list.head = n;
    } else {                                    // if n is not the first node,
        n->prev->next = n;                      // link previous node forward to n              p <-> n <-> t
    }

    return Iterator(n);                         // return a pointer to the newly inserted node
}
// Remove a specified node from the list
// If successful, return an iterator to the node after the erased node, if this is the end of list return an iterator to nullptr
// If unsuccesful, return the original iterator
Iterator erase(List &list, Iterator it)
{
    if( empty(list) || it.current == nullptr ) {
        return it;                              // if list is empty or iterator invalid, exit, return original iterator  
    } else if( it.current == list.head) {       // if iterator points to the first node, pop_front, return new Iterator to new first node
        pop_front(list);
        return list.begin();
    } else if( it.current == list.tail ) {      // if iterator points to last node, pop_back, return nullptr
        pop_back(list);
        return Iterator(nullptr);
    }

    Node *n = it.current->next;                 // point n to node after iterator:                                  b <-> it <-> a
    it.current->prev->next = it.current->next;  // link node before iterator forwards to node after iterator:       b  -> a
    it.current->next->prev = it.current->prev;  // link node after iterator backwards to node before iterator:      b <-> a
    
    delete it.current;                          // remove the iterator node

    return Iterator(n);                         // return the node after the iterator node
}
// Print a list in forward order
void print(List &list)                          // print the list
{
    Iterator itr = list.begin();                // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator forwards through all nodes in list   
        std::cout << itr.getData() << " ";      // print the data of the iterator node
        itr.next();                             // point the iterator to the next node
    }   
    std::cout << "\n";    
}
// Print a list in reverse order
void printRev(List &list)                       // print the list
{
    Iterator itr = list.rbegin();               // point iterator to the last node   
    while( itr.hasPrev() ) {                    // advance the iterator backwards through all nodes in list   
        std::cout << itr.getData() << " ";      // print the data of the iterator node
        itr.prev();                             // point the iterator to the previous node
    }   
    std::cout << "\n";    
}
// Copy one list to another list
void duplicate(List &a, List &b)                // duplicate list a contents into list b
{
    Iterator itr = a.begin();                   // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator through all nodes in list   
        push_back(b, itr.getData());            // copy the data of the iterator node from list A into list B
        itr.next();                             // point the iterator to the next node
    }   
}
// Determine if the value d is in the list. 
// If successful, return an iterator to the node that stores data equivalent to d
// if unsuccessful, return an interator pointing to nullptr
Iterator find(List &list, int d)             
{
    Iterator itr = list.begin();                // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator through all nodes in list  
        if( itr.getData() == d ) {              // if node n stores the equivalent of d, 
            return itr;                         // return an iterator to the node storing the equivalent of d
        }
        itr.next();                             // point iterator to the next node
    }   
    return Iterator(nullptr);                   // if data was not found, return iterator pointing to nullptr
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

    Iterator it = list.begin();                 // point an iterator to the start of the list

    std::cout << "\nFRONT/BACK\n";              // test front/back
    std::cout << front(list) << "\n";       
    std::cout << back(list) << "\n";
    print(list);   

    std::cout << "\nFIND/INSERT\n";             // test find and insert 
    it = find(list, 200);
    std::cout << "Insert 100 before " 
              << it.getData() << "\n";          // test return value    
    it = insert(list,it, 100);                  // insert 100 before 200 (edge case)
    std::cout << "Returned Iterator: " 
              << it.getData() << "\n";          // test return value
    it = find(list, 400);   
    it = insert(list, it, 300);                 // insert 300 before 400  (middle case)    
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";              // test erase and insert 
    it = find(list, 100);
    std::cout << "Erase 100 " << "\n";        
    it = erase(list, it);                       // erase 100 (edge case)
    std::cout << "Returned Iterator: " 
              << it.getData() << "\n";          // test return value
    it = find(list, 300);   
    it = erase(list, it);                       // erase 300 (middle case)  
    it = find(list, 800);   
    it = erase(list, it);                       // erase 800 (edge case)  
    print(list);
    printRev(list);   

    std::cout << "\nCOPY\n";                    // test duplicate
    List list_copy;
    duplicate(list, list_copy);                 // duplicate list without sharing memory
    it = find(list, 200);                       // erase a node to modify the original list
    erase(list, it);                              
    print(list);
    print(list_copy);                           // test if the copy contains the original data to check for distinct memory allocation                    

    std::cout << std::endl;
    return 0;
}



