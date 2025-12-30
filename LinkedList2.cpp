#include <iostream>
#include <algorithm>
#include <vector>
#include <optional>

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

        // this returns an address:
        Node<T>* get(int idx){
            if(idx < 0 || idx >= length) return nullptr;

            Node<T>* cur = head;
            for(int i = 0; i < idx; i++){
                cur = cur->next;
            }
            return cur;
        }

        bool set(int idx, T value){
            Node<T>* temp = get(idx);
            if(temp){
                temp->val = value;
                return true;
            }
            return false;
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

    myLL->set(1, 4);
    myLL->printList();

    // std::cout << "Head: " << myLL->getHead() << '\n';
    // std::cout << "Tail: " << myLL->getTail() << '\n';
    // std::cout << "Length: " << myLL->getLength() << '\n';

    return 0;
}