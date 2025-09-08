#include <iostream>

struct Node{
    int val;
    Node* prev = nullptr;
    Node* next;
};

void printForward(Node* head){
    Node* cur = head;
    while(cur){
        std::cout << cur->val << " -> ";
        cur = cur->next;
    }
    std::cout << "NULL" << '\n';
}

void printReverse(Node* head){
    Node* cur = head;
    while(cur->next){cur = cur->next;}

    // reverse traversal
    while(cur){
        std::cout << cur->val << " -> ";
        cur = cur->prev;
    }
    std::cout << "Reached Head";
}

void insertAtHead(Node*& head, int x){
    Node* newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head == nullptr){
        head = newNode;
        return;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode; 
    }
}

int main(){
    
    Node* head = nullptr;
    printForward(head);
    insertAtHead(head, 1);
    printForward(head);
    insertAtHead(head, 2);
    printForward(head);
    printReverse(head);

    return 0;
}