#include <iostream>

template <typename E> class DLinkedList;

template <typename E> 
class Dnode{
private:
    E val;
    Dnode<E>* next;
    Dnode<E>* prev;
    friend class DLL<E>;
};

template <typename E>
class DLinkedList{
public:
    DLinkedList(); // constructor
    ~DLinkedList(); // destructor
    bool empty() const; // is list empty?
    const E& front() const; // get front element
    const E& back() const; // get back element
};