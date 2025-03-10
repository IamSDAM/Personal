// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

/*
    Singly Linked List

    head                                       tail
        \                                       /
        node    ->  node    ->  node    ->  node    ->  nullptr

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
    if( empty(list) ) {                         // if list is empty: push_front and exn
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
    if( empty(list) ) {                         // if list is empty: exn
        return; 
    }

    Node *n = list.head;                        // point n to the first node
    list.head = list.head->next;                // second node becomes the new first node
    delete n;                                   // delete the original first node

    if(list.head == nullptr) {                  // if list will be empty, reset tail for an empty list
        list.tail = nullptr; 
    }   
}
// Add a node after node t in the list
// If successful, return a pointer to the new node, otherwise return a pointer to the t node
Node* insertAfter(List &list, Node *t, const int &d)
{   
    if( empty(list) || t == nullptr ) {         // if list is empty or t invalid, 
        return t;                               // exn and return a pointer to node t
    }

    Node *n = new Node(d);                      // point n to a new node
    n->next = t->next;                          // link n before the node after t
    t->next = n;                                // link t before node n

    if(n->next == nullptr) { list.tail = n; }   // if t was the second to last node, n becomes the new last node

    return n;                                   // return a pointer to the newly inserted node
}
/*
    Singly Linked List

    head                        t, tail tail
        \                       |    
        node    ->  node    ->  node    ->  nullptr
  
*/

// Remove a node after node t in the list
// If successful, return a pointer to the node after the erased node, if that is the end of list return nullptr
// If unsuccesful, return a pointer to node t
Node* eraseAfter(List &list, Node *t)
{
    if( empty(list) || t == nullptr || t->next == nullptr ) {
        return t;                               // if list is empty, t invalid or t is the end of list, exn, return pointer to node t   
    }        

    Node *n = t->next;                          // point n to the node after t
    t->next = n->next;                          // link t before the node that is after n

    if( n->next == nullptr ) { list.tail = t; } // if n (the node to remove) is the last node, update tail to point to t

    delete n;                                   // remove the node after t (n)

    return t->next;                             // return a pointe to node after the erased node
}
// Print a list in forward order
void print(const List &list) {                              
    Node *n = list.head;                        // point n to the first node                                       
    while(n != nullptr) {                       // advance n through all nodes in list        
        std::cout << n->data << " ";            // print the data of node n   
        n = n->next;                            // point n to the next node
    }
    std::cout << "\n";
}


// Copy one list to another list
void duplicate(const List &a, List &b)
{
    Node *n = a.head;                           // point n to the first node in list A
    while(n != nullptr) {                       // advance n through all nodes in list A until n reaches the end
        push_back(b, n->data);                  // copy the data from node n in list A into list B
        n = n->next;                            // point n to the next node in list A
    }    
}

// Determine if the value d is in the list. If so, return a pointer to the node that stores n, otherwise return nullptr
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

    Node *n = nullptr;                          // create a node pointer

    std::cout << "\nFIND/INSERT AFTER\n";       // test find and insert after
    std::cout << "Find 200 " << "\n";      
    n = find(list, 200);                        // return an iterator to 200
    std::cout << "Insert 300 after " 
              << n->data << "\n";                  
    n  = insertAfter(list, n, 300);             // insert 300 after 200 (middle case)
    std::cout << "Insert will return iterator to: " 
              << n->data << "\n";               
    print(list);
    std::cout << "Find 800 " << "\n";      
    n  = find(list, 800);
    std::cout << "Insert 900 after " 
              << n->data << "\n";               // test return value         
    n  = insertAfter(list, n, 900);             // insert 900 after 800 (edge case: insert a new tail node)   
    std::cout << "Insert will return iterator to: " 
              << n->data << "\n";                    
    print(list);

    std::cout << "\nFIND/ERASE AFTER\n";        // test erase after 
    std::cout << "Find 300 " << "\n";  
    n  = find(list, 300);                       // return an iterator to 300
    std::cout << "Erase node after: "             
              << n->data << "\n";       
    n = eraseAfter(list, n);                    // erase node after 300, return pointer to node after erased node  (middle case)
    std::cout << "Erase will return iterator to: " 
              << n->data << "\n";               
    print(list);
    std::cout << "Find 800 " << "\n";                   
    n  = find(list, 800);                       // return an iterator to 800
    std::cout << "Erase node after: "            
              << n->data << "\n";   
    std::cout << "Erase will return " 
              << "iterator to nullptr\n";                   
    n  = eraseAfter(list, n);                   // erase node after 800 (tail node), return pointer to nullptr  (edge case)    
    print(list);

    std::cout << "\nCOPY\n";                    // test duplicate
    List list_copy;
    duplicate(list, list_copy);                 // duplicate list wnhout sharing memory
    n = find(list, 300);                        // erase a node to modify the original list
    eraseAfter(list, n);                              
    print(list);
    print(list_copy);                           // test if the copy contains the original data to check for distinct memory allocation                                   

    std::cout << std::endl;
    return 0;
}