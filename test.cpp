#include <iostream>
#include "SLLclass.hpp"
#include "DLLclass.hpp"
#include "quicksortTemplate.hpp"
#include "mergesortTemplate.hpp"
#include <ctime>

int main(){

    // SLinkedList<int> nums;
    // nums.insertAtEnd(1);
    // nums.insertAtEnd(2);
    // nums.insertAtEnd(3);
    // nums.addFront(0);
    // nums.printList();

    // DLinkedList<std::string> movies;

    // movies.addBack("Conjuring");
    // movies.addBack("Toy Story");
    // movies.addFront("Social Network");
    // movies.printList();

    // srand(time(NULL));
    // std::vector<int> numVec;
    // for(int i = 0; i < 10; i++){
    //     int x = rand() % 100 + 1;
    //     numVec.push_back(x);
    // }

    // for(auto x : numVec) std::cout << x << ' ';

    // std::cout << '\n';

    // quicksort(numVec, 0, numVec.size()-1);

    // for(auto x : numVec) std::cout << x << ' ';

    // std::cout << '\n';

    std::vector<int> nums1 = {3,1,2,4,5,1,3,8,9,56,4,11,32,12};
    for(int x : nums1){std::cout << x << ' ';}
    std::cout << '\n';
    mergeSort(nums1);
    for(int x : nums1){std::cout << x << ' ';}
    std::cout << '\n';

    int nums2[5] = {3,1,5,2,4};
    for(int x : nums2){std::cout << x << ' ';}
    std::cout << '\n';
    mergeSort(nums2, 5);
    for(int x : nums2){std::cout << x << ' ';}
    std::cout << '\n';


    return 0;
}