#include <iostream>
#include <algorithm>
#include <vector>

template <typename T> class LinkedList;

template <typename T>
class Node{
    private:
        T val;
        Node* next;
    public:
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
        LinkedList(T val){
            Node<T>* newNode = new Node<T>(val);
            this->head = newNode;
            this->tail = newNode;
            this->length = 1;
        }

        T getHead(){
            return this->head->val;
        }
        
        T getTail(){
            return this->tail->val;
        }

        int getLength(){return this->length;}

        void printList();

        ~LinkedList(){
            Node<T>* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

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

        Node<T>* get(int idx){
            if(idx < 0 || idx >= length) return nullptr;

            Node<T>* cur = head;
            for(int i = 0; i < idx; i++){
                cur = cur->next;
            }
            return cur;
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

    LinkedList<int>* myLL = new LinkedList<int>(10);
    myLL->append(11);
    myLL->append(12);

    myLL->printList();
    
    myLL->deleteLast();
    
    myLL->printList();

    myLL->prepend(9);

    myLL->printList();

    myLL->deleteFirst();
    myLL->printList();

    std::cout << "Head: " << myLL->getHead() << '\n';
    std::cout << "Tail: " << myLL->getTail() << '\n';
    std::cout << "Length: " << myLL->getLength() << '\n';

    return 0;
}