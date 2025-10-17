#include <iostream>
#include <queue>

int main(){

    std::priority_queue<int> maxHeap;    // by default, std::priorityQ is maxHeap

    maxHeap.push(1);
    maxHeap.push(2);
    maxHeap.push(3);

    while(!maxHeap.empty()){
        std::cout << maxHeap.top() << '\n';
        maxHeap.pop();
    }

    std::cout << '\n';

    // to make minHeap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // follow this format

    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(3);

    while(!minHeap.empty()){
        std::cout << minHeap.top() << '\n';
        minHeap.pop();
    }


    return 0;
}