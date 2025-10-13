#include <iostream>
#include "SLLclass.hpp"
#include "DLLclass.hpp"
#include "quicksortTemplate.hpp"
#include <ctime>

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

    srand(time(NULL));
    std::vector<int> numVec;
    for(int i = 0; i < 10; i++){
        int x = rand() % 100 + 1;
        numVec.push_back(x);
    }

    for(auto x : numVec) std::cout << x << ' ';

    std::cout << '\n';

    quicksort(numVec, 0, numVec.size()-1);

    for(auto x : numVec) std::cout << x << ' ';

    std::cout << '\n';


    return 0;
}