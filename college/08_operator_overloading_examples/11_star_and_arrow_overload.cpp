// S. Trowbridge 2024
#include <iostream>

class Thing {  
    private:
        int num;
    public:
        Thing(): num(0) {}
        Thing(int n): num(n) {}
        void setData(int n) { num = n; }
        int getData() const { return num; }
        friend std::ostream& operator<<(std::ostream &out, const Thing &t);
};
std::ostream& operator<<(std::ostream &out, const Thing &t) // overload << to print Thing objects
{
    out << t.num;
    return out;
}

struct Node {
    Thing data;                                              
    Node *next;   
    Node(): data(), next(nullptr) {}                      
    Node(const Thing &t): data(t), next(nullptr) {}                                
};

/*
    num     num
    |       |
    t       t
    |       |
    n   ->  n   ->  nullptr;
            |
            it->num;
*/

struct Iterator {
    Node *current;
    Iterator(Node *n): current(n) {
    }
    Iterator& operator++() {                                // overload prefix ++ - increment iterator to next node
        current = current->next;
        return *this;
    } 
    Iterator operator++(int) {                              // overload postfix ++ - increment iterator to next node
        Iterator temp{*this};
        current = current->next;
        return temp;
    }
    bool operator==(Iterator const &rhs) const {            // overload equivalence - do two iterators point to the same node
        return current == rhs.current;
    }        
    bool operator!=(Iterator const &rhs) const {            // overload inequivalence - do two iterators point to different nodes
        return current != rhs.current;
    }
    Thing& operator*() const {                              // overload star - return a reference to the data inside the current node
        return current->data;
    }
    Thing* operator->() const {                             // overload arrow - return a pointer to the data inside the current node
        return &(current->data);
    }       
};

struct List {                                               
    Node *head;                                                                       
    Node *tail;                                 
    List(): head(nullptr), tail(nullptr) {}     
    ~List()                                     
    {
        Node *n = head;                        
        Node *backup = nullptr;
        while(n != nullptr) {                   
            backup = n;                         
            n = n->next;                        
            delete backup;                      
        }
    }      
    Iterator begin() {                          
        return Iterator(head);
    }  
    Iterator end() {                            
        return Iterator(nullptr);
    }                 
};
bool empty(List &list)
{
    if(list.head == nullptr) {
        return true;
    } else {
        return false; 
    }
}
void push_front(List &list, const Thing &d)            
{
    Node *n = new Node(d);                                                     
    n->next = list.head;                             
    list.head = n;                              
    if(list.tail == nullptr) { list.tail = n; } 
}
void push_back(List &list, const Thing &d)                               
{
    if( empty(list) ) {                         
        push_front(list, d);
        return;
    }
    Node *n = new Node(d);                      
    list.tail->next = n;                                            
    list.tail = n;                              
}

int main() {
    std::cout << std::endl;

    List list; 

    push_front(list, Thing(200));
    push_front(list, Thing(100));
    push_back(list, Thing(400));     
    push_back(list, Thing(600));
    push_back(list, Thing(800)); 

    Iterator it = list.begin();                 // point an iterator to the first node
    while( it != list.end() ) {                  // iterate until the end
        std::cout << *it << " ";                // access the node and return the Thing object (the << overload of Thing then prints the value of num)
        ++it;                                   // advance the iterator forwards to the next node
    }
    std::cout << std::endl;

    it = list.begin();                          // point iterator to the first node
    it->setData(50000);                         // arrow operator used to write the value of num inside of a Thing inside of a Node
    std::cout << it->getData() << std::endl;    // arrow operator used to read the value of num inside of a Thing inside of a Node

    std::cout << std::endl;
    return 0;
}