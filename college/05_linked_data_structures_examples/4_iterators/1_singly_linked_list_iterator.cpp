// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct Iterator {
    Node *current;                                      // target node
    Iterator(Node *n): current(n) {                     // point iterator to specific node
    }
    void next() {                                       // advance iterator to next node
        current = current->next;
    }
    bool hasNext() {                                    // return true if current is a valid node (not nullptr), false otherwise
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    } 
    int& getData() {                                    // return a reference to the data stored in the current node
        return current->data;
    }
};

/*
    Singly Linked List with Iterator

    head                                       tail
        \                                       /
        node    ->  node    ->  node    ->   node   ->  nullptr
        |
        Iterator -->>
*/

struct List {                                               
    Node *head;                                 // pointer to the first node                                             
    Node *tail;                                 // pointer to the last node
    List(): head(nullptr), tail(nullptr) {}     // constructor: construct an empty list
    ~List()                                     // destructor: safe deletion of all nodes in the list
    {
        Node *n = head;                         // point n to the first node
        Node *backup = nullptr;
        while(n != nullptr) {                   // advance n through all nodes in the list
            backup = n;                         // point backup to node n
            n = n->next;                        // advance n to the next node
            delete backup;                      // delete the backup node
        }
    }      
    Iterator begin() {                          // return an iterator pointing to the first node
        return Iterator(head);
    }  
    Iterator end() {                            // return an iterator to the value past the end of the list (nullptr)
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
// Add a node to the front of the list   
void push_front(List &list, const int &d)            
{
    Node *n = new Node(d);                      // point n to a new node                                   
    n->next = list.head;                        // link n before the first node      
    list.head = n;                              // n becomes the new first node

    if(list.tail == nullptr) { list.tail = n; } // if list was empty, n becomes the new last node
}
// Add a node to the back of the list 
void push_back(List &list, const int &d)                               
{
    if( empty(list) ) {                         // if list is empty: push_front and exit
        push_front(list, d);
        return;
    }
    
    Node *n = new Node(d);                      // point n to new node
    list.tail->next = n;                        // link n after the last node                      
    list.tail = n;                              // n becomes the new last node
}
// Remove the first node in the list
void pop_front(List &list)                      
{
    if( empty(list) ) {                         // if list is empty: exit
        return; 
    }

    Node *n = list.head;                        // point n to the first node
    list.head = list.head->next;                // second node becomes the new first node
    delete n;                                   // delete the original first node

    if(list.head == nullptr) {                  // if list will be empty, reset tail for an empty list
        list.tail = nullptr; 
    }   
}
// Add a new node after a specified node in the list
// If successful, return an iterator to the new node, otherwise return the original iterator
Iterator insertAfter(List &list, Iterator it, const int &d)
{   
    if( empty(list) || it.current == nullptr) { // if list is empty or iterator invalid, 
        return it;                              // exit and return the original iterator
    }

    Node *n = new Node(d);                      // point n to a new node
    n->next = it.current->next;                 // link n before the node after the iterator node
    it.current->next = n;                       // link the iterator node before node n

    if(n->next == nullptr) { list.tail = n; }   // if t was the second to last node, n becomes the new last node

    return Iterator(n);                         // return an iterator to the newly inserted node
}
// Remove a node after a specified node from the list
// If successful, return an iterator to the node after the erased node, if that is the end of list return nullptr
// If unsuccesful, return the original iterator
Iterator eraseAfter(List &list, Iterator it)
{
    if( empty(list) || it.current == nullptr || it.current->next == nullptr) { 
        return it;                              // if list is empty, iterator invalid or iterator points to last node,             
    }                                           // exit and return the original iterator   

    Node *n = it.current->next;                 // point n to the node after t
    it.current->next = n->next;                 // link iterator before the node that is after n

    if( n->next == nullptr ) { list.tail = it.current; } // if n is the last node, update tail to point to the it node

    delete n;                                   // remove the node after t (n)

    return Iterator(it.current->next);          // return an iterator to the node after the erased node
}
// Print a list in forward order
void print(List &list)                          // print the list
{
    Iterator itr = list.begin();                // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator through all nodes in list   
        std::cout << itr.getData() << " ";      // print the data of the iterator node
        itr.next();                             // point the iterator to the next node
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
    push_front(list, 200);
    push_front(list, 100);
    push_back(list, 400);     
    push_back(list, 600);
    push_back(list, 800);
    print(list);                                // test forward traversal

    std::cout << "\nPOP FRONT\n";               // test pop front
    pop_front(list);
    print(list);

    std::cout << "\nFRONT\n";                   // test front
    std::cout << front(list) << "\n";
    print(list);

    Iterator it = list.begin();                 // point iterator to list head node (the first node)

    std::cout << "\nFIND/INSERT AFTER\n";       // test find and insert after
    std::cout << "Find 200 " << "\n";      
    it = find(list, 200);                       // return an iterator to 200
    std::cout << "Insert 300 after " 
              << it.getData() << "\n";                      
    it = insertAfter(list, it, 300);            // insert 300 after 200 (middle case)
    std::cout << "Insert will return iterator to: " 
              << it.getData() << "\n";
    print(list);
    std::cout << "Find 800 " << "\n";      
    it = find(list, 800);                       // return an iterator to 800
    std::cout << "Insert 900 after " 
              << it.getData() << "\n";        
    it = insertAfter(list, it, 900);            // insert 900 after 800 (edge case: insert a new tail node)   
    std::cout << "Insert will return iterator to: " 
              << it.getData() << "\n";     
    print(list);

    std::cout << "\nFIND/ERASE AFTER\n";        // test erase after 
    std::cout << "Find 300 " << "\n";  
    it = find(list, 300);                       // return an iterator to 300
    std::cout << "Erase node after: "  
              << it.getData() << "\n";       
    it = eraseAfter(list, it);                  // erase node after 300, return pointer to node after erased node  (middle case)
    std::cout << "Erase will return iterator to: " 
              << it.getData() << "\n";          
    print(list);
    std::cout << "Find 800 " << "\n";                   
    it = find(list, 800);                       // return an iterator to 800
    std::cout << "Erase node after: "
              << it.getData() << "\n";   
    std::cout << "Erase will return " 
              << "iterator to nullptr\n";            
    it = eraseAfter(list, it);                  // erase node after 800 (tail node), return pointer to nullptr  (edge case)    
    print(list);

    std::cout << "\nCOPY\n";                    // test duplicate
    List list_copy;
    duplicate(list, list_copy);                 // duplicate list without sharing memory
    it = find(list, 300);                       // erase a node to modify the original list
    eraseAfter(list, it);                              
    print(list);
    print(list_copy);                           // test if the copy contains the original data to check for distinct memory allocation                                   

    std::cout << std::endl;
    return 0;
}