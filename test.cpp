#include <iostream>
#include "SLLclass.hpp"
#include "DLLclass.hpp"

int main(){

    SLinkedList<int> nums;
    nums.insertAtEnd(1);
    nums.insertAtEnd(2);
    nums.insertAtEnd(3);
    nums.addFront(0);
    nums.printList();

    DLinkedList<std::string> movies;

    movies.addBack("Conjuring");
    movies.addBack("Toy Story");
    movies.addFront("Social Network");
    movies.printList();

    return 0;
}