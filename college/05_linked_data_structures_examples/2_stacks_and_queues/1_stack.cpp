// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

/*
    Stack

    top ->  node
            |
            node
            |  
            node
            |
            nullptr
                   
*/ 
struct Stack {
    Node *topNode;                                  // pointer to the top of the stack
    Stack(): topNode(nullptr) {}                    // constructor: construct an empty stack
    ~Stack()                                        // destructor: safe deletion of all nodes in the stack
    {
        Node *n = topNode;                          // point n to the top node
        Node *backup = nullptr;                           
        while(n != nullptr) {                       // advance n through all nodes in the stack
            backup = n;                             // point backup to node n
            n = n->next;                            // advance n to the next node
            delete backup;                          // remove the backup node
        }
    }
};
bool empty(Stack &stack)                            // return true if the stack is empty, false otherwise
{
    if( stack.topNode == nullptr ) {                
        return true;
    } else {
        return false;
    }
}
int& top(Stack &stack) {
    return stack.topNode->data;                     // return a reference to the data inside the topNode
}
void push(Stack &stack, const int &d)
{
    Node *n = new Node(d);                          // point n to a new node
    n->next = stack.topNode;                        // link b before the first node
    stack.topNode = n;                              // n becomes the new first node
}
void pop(Stack &stack) 
{
    if( empty(stack) ) { return; }                  // if stack is empty, exit
    Node *n = stack.topNode;                        // point n to the first node
    stack.topNode = stack.topNode->next;            // second node becomes the new first node
    delete n;                                       // remove the original first node
}
void print(const Stack &stack) 
{
    Node *n = stack.topNode;                        // point n to the first node
    while(n != nullptr) {                           // advance n through all nodes in the stack
        std::cout << n->data << " ";                // print n node data
        n = n->next;                                // advance n to the next node
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

    Stack stack;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    print(stack);   

    std::cout << "\n" << top(stack) << "\n\n";             

    pop(stack);
    pop(stack);
    print(stack);

    std::cout << "\n" << top(stack) << "\n\n";           

    std::cout << std::endl;    
    return 0;
}