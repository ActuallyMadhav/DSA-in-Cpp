#ifndef LLCLASS_HPP
#define LLCLASS_HPP

#include <iostream>

template <typename E> class SLinkedList;

template <typename E>
class Snode{
private:
    E val;
    Snode<E>* next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList{
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void insertAtEnd(const E& e);
    void removeFront();
    void printList();
    Snode<E>* reverseList(Snode<E>*& head);
    Snode<E>* head;

// private:
//     Snode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList()
    : head(NULL){}      // constructor

template <typename E>
bool SLinkedList<E>::empty() const{
    return head == nullptr;     // is the list empty?
} 

template <typename E>
void SLinkedList<E>::printList(){
    Snode<E>* cur = head;
    while(cur != nullptr){
        std::cout << cur->val << " -> ";    // traverse list and print all elements
        cur = cur->next;
    }
    std::cout << "NULL" << '\n';
}

template <typename E>
void SLinkedList<E>::insertAtEnd(const E& e){
    Snode<E>* newNode = new Snode<E>;
    newNode->val = e;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
    }
    else{
        Snode<E>* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename E>
const E& SLinkedList<E>::front() const{
    if(empty()){
        std::cout << "Empty List";
    }
    return head->val;       // return first element
}

template <typename E>
void SLinkedList<E>::addFront(const E& e){
    Snode<E>* newNode = new Snode<E>;   // create new node
    newNode->val = e;       // store data
    newNode->next = head;   // head follows newNode
    head = newNode;         // newNode is now head
}

template <typename E>
void SLinkedList<E>::removeFront(){
    if(empty()){
        std::cout << "Empty List";
    }
    Snode<E>* old = head;   // store current head
    head = old->next;       // skip current head
    delete old;             // delete old head
}

template <typename E>
SLinkedList<E>::~SLinkedList(){
    while(!empty()){
        removeFront();      // destructor
    }
}

template <typename E>
Snode<E>* SLinkedList<E>::reverseList(Snode<E>*& head){
    Snode<E>* cur = head;
    Snode<E>* prev = nullptr;

    while(cur){
        Snode<E>* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
    return head;
}

#endif