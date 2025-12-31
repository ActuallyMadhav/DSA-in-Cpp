#include <iostream>
#include <algorithm>
#include <vector>

template <typename T> class LinkedList;

template <typename T>
class Node{
    public:
        T val;
        Node* next;
    
        Node(T val){
            this->val = val;
            this->next = nullptr;
        }
    friend class LinkedList<T>;
};

template <typename T>
class LinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
    
    public:
        // constructor
        LinkedList(T val){
            Node<T>* newNode = new Node<T>(val);
            this->head = newNode;
            this->tail = newNode;
            this->length = 1;
        }

        // getters
        T getHead(){
            return this->head->val;
        }
        
        T getTail(){
            return this->tail->val;
        }

        int getLength(){return this->length;}

        // print list, defined outside
        void printList();

        // destructor
        ~LinkedList(){
            Node<T>* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        // add node at end - append node
        void append(T val){
            Node<T>* newNode = new Node<T>(val);
            if(!head){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        // delete last node
        void deleteLast(){
            if(!head) return;

            Node<T>* cur = head;

            if(length == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
            }

            else{
                while(cur->next->next){
                    cur = cur->next;
                }
                delete cur->next;
                tail = cur;
                tail->next = nullptr;
            }
            length--;
        }

        // add node at beginning - prepend node
        void prepend(T value){
            Node<T>* newNode = new Node<T>(value);
            if(!head){
                head = newNode;
                tail = newNode;
                head->next = nullptr;
                tail->next = nullptr;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        // delete first node
        void deleteFirst(){
            if(!head) return;

            Node<T>* temp = head;
            if(length == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else{
                head = head->next;
            }
            delete temp;
            length--;
        }

        // this returns an address:
        // get node at index
        Node<T>* get(int idx){
            if(idx < 0 || idx >= length) return nullptr;

            Node<T>* cur = head;
            for(int i = 0; i < idx; i++){
                cur = cur->next;
            }
            return cur;
        }

        // set value of node at index
        bool set(int idx, T value){
            Node<T>* temp = get(idx);
            if(temp){
                temp->val = value;
                return true;
            }
            return false;
        }
        
        // insert at index
        void insert(int index, T value){
            if(index < 0 || index > length){
                std::cout << "Invalid index" << '\n';
                return;
            }

            if(index == 0){
                prepend(value); // prepend increments length
            }
            else if(index == length){
                append(value);  // append increments length
            }
            else{
                Node<T>* newNode = new Node<T>(value);
                Node<T>* cur = head;

                for(int i = 0; i < index-1; i++){   // stop before index
                    cur = cur->next;
                }
                newNode->next = cur->next;
                cur->next = newNode;
                length++;
            }
        }
};

template <typename T>
void LinkedList<T>::printList(){
    Node<T>* cur = head;
    while(cur){
        std::cout << cur->val << ' ';
        cur = cur->next;
    }

    std::cout << '\n';
}


int main(){

    LinkedList<int>* myLL = new LinkedList<int>(0);

    myLL->append(1);
    myLL->append(2);
    myLL->append(3);

    myLL->printList();

    // myLL->set(1, 4);
    // myLL->printList();

    // myLL->insert(0, -1);
    // myLL->insert(5, 4);
    // myLL->insert(3, 7);
    // myLL->printList();

    // std::cout << "Head: " << myLL->getHead() << '\n';
    // std::cout << "Tail: " << myLL->getTail() << '\n';
    // std::cout << "Length: " << myLL->getLength() << '\n';

    return 0;
}