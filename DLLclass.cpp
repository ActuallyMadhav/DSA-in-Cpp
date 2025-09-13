#include <iostream>
#include <list>     // in built doubly linked list from stl

template <typename E> class DLinkedList;

template <typename E> 
class Dnode{
private:
    E val;
    Dnode<E>* next;
    Dnode<E>* prev;
    friend class DLinkedList<E>;
};

template <typename E>
class DLinkedList{
public:
    DLinkedList(); // constructor
    ~DLinkedList(); // destructor
    bool empty() const; // is list empty?
    const E& front() const; // get front element
    const E& back() const; // get back element
    void addFront(const E& e);  // insert element at front
    void addBack(const E& e);   // insert element at back
    void removeFront(); // remove front element
    void removeBack();  // remove back element
    void printList(); // print list

private:
    Dnode<E>* head;
    Dnode<E>* tail;

protected:
    void add(Dnode<E>* v, const E& e);  // insert node after v
    void remove(Dnode<E>* v);   // remove v
};

template <typename E>
DLinkedList<E>::DLinkedList(){      // class constructor
    head = new Dnode<E>;
    tail = new Dnode<E>;
    head->next = tail;      // point head and tail at each other
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
}

template <typename E>
bool DLinkedList<E>::empty() const{
    return (head->next == tail);        // is the list empty
}

template <typename E>
DLinkedList<E>::~DLinkedList(){     // class destructor
    while(!empty()) removeFront();
    delete head;        // delete head and tail
    delete tail;
}

template <typename E>
const E& DLinkedList<E>::front() const{
    return head->next->val;     // return first element
}

template <typename E>
const E& DLinkedList<E>::back() const{
    return tail->prev->val;     // return final val
}

template <typename E>
void DLinkedList<E>::add(Dnode<E>* v, const E& e){
    Dnode<E>* u = new Dnode<E>;
    u->val = e;
    u->next = v;
    u->prev = v->prev;
    if(v->prev){
        v->prev->next = u;
    }
    v->prev = u;
    if(v == head->next){
        head->next = u;
    }
}

template <typename E>
void DLinkedList<E>::addFront(const E& e){
    add(head->next, e);     // add to front of list
}

template <typename E>
void DLinkedList<E>::addBack(const E&e){
    add(tail, e);
}

template <typename E>
void DLinkedList<E>::remove(Dnode<E>* v){
    if(v == head || v == tail) return;      // dont delete sentinels
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

template <typename E>
void DLinkedList<E>::removeBack(){
    remove(tail->prev);     // remove from back
}

template <typename E>
void DLinkedList<E>::removeFront(){
    remove(head->next);     // remove from front
}

template <typename E>
void DLinkedList<E>::printList(){
    Dnode<E>* cur = head;
    while(cur != nullptr){
        std::cout << cur->val << " <-> ";
        cur = cur->next; 
    }
    std::cout << "NULL" << '\n';
}

int main(){
    DLinkedList<int> numList;

    std::cout << numList.empty() << '\n';
    numList.addFront(1);
    numList.addFront(0);
    numList.addFront(-1);
    numList.addBack(2);
    numList.addBack(3);
    numList.printList();
    std::cout << numList.empty() << '\n';

    return 0;
}