// S. Trowbridge 2024
#include <iostream>

struct Node {
    int data;                                              
    Node *next;  
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

/*
    Queue

    front                                       back
        \                                       /
        node    ->  node    ->  node    ->  node    ->  nullptr

*/
struct Queue {
    Node *front;                                    // pointer to the front of the queue
    Node *back;                                     // pointer to the back of the queue    
    Queue(): front(nullptr), back(nullptr) {}       // constructor: construct an empty queue
    ~Queue()                                        // destructor: safe deletion of all nodes in the queue
    {
        Node *n = front;                            // point n to the first node
        Node *backup = nullptr;                           
        while(n != nullptr) {                       // advance n through all nodes in the queue
            backup = n;                             // point backup to node n
            n = n->next;                            // advance n to the next node
            delete backup;                          // remove the backup node
        }
    }
};

bool empty(Queue &queue)                            // return true if the queue is empty, false otherwise
{
    if(queue.front == nullptr) {
        return true;
    } else {
        return false;
    }
}
int& front(Queue &queue)                    
{
    return queue.front->data;                       // return a reference to the data in the front node
}
int& back(Queue &queue)
{
    return queue.back->data;                        // return a reference to the data in the back node
}
void push(Queue &queue, const int &d)
{
    Node *n = new Node(d);                          // point n to a new node
    if( empty(queue) ) {                            // if queue is empty, 
        queue.front = n;                            //      n becomes the first node
        queue.back = n;                             //      n becomes the last node
    } else {                                        // if queue has data,
        queue.back->next = n;                       //      link n after the last node
        queue.back = n;                             //      n becomes the new last node
    }
}
void pop(Queue &queue) 
{
    if( empty(queue) ) { return; }                  // if queue is empty, exit
    Node *n = queue.front;                          // point n to the first node
    queue.front = queue.front->next;                // second node becomes the new first node
    if(queue.front == nullptr) { queue.back = nullptr; }    // if queue is now empty, reset back for an empty queue
    delete n;                                       // remove the original first node
}
void print(const Queue &queue) 
{
    Node *n = queue.front;                          // point n to the first node
    while(n != nullptr) {                           // advance n through all nodes in the queue
        std::cout << n->data << " ";                // print n node data
        n = n->next;                                // point n to the next node
    }
    std::cout << std::endl;
}  
int main() {
    std::cout << std::endl;

    Queue queue;

    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    push(queue, 50);

    print(queue);   

    std::cout << "\n" <<front(queue) << " " << back(queue) << "\n\n";

    pop(queue);
    pop(queue);
    print(queue);

    std::cout << "\n" <<front(queue) << " " << back(queue) << "\n\n";

    std::cout << std::endl;    
    return 0;
}