#include <iostream>
#include <vector>

template <typename T>
class Node{
public:
    T val;
    Node<T>* next;

    //constructor
    Node(T val){
        this->val = val;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    
    // constructor
    LinkedList(T value){
        Node<T>* newNode = new Node<T>(value);
        this->head = newNode;
        this->tail = newNode;
        this->length = 1;
    }

    // destructor
    ~LinkedList(){
        Node<T>* temp = this->head;
        while(this->head){
            this->head = this->head->next;
            delete temp;
            Node<T>* temp = this->head;
        }
    }

    // printing values
    void printList(){
        Node<T>* temp = this->head;

        while(temp){
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
    }

    void getHead(){
        std::cout << "Head: " << this->head->val << '\n';
    }

    void getTail(){
        std::cout << "Tail: " << this->tail->val << '\n';
    }

    void getLength(){
        std::cout << "Length: " << this->length << '\n';
    }

    void append(T value){
        Node<T>* newNode = new Node<T>(value);

        if(!this->length){  // if length == 0
            this->head = newNode;
            this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        (this->length)++;
    }
};