#include <iostream>
#include <queue>
#include <vector>

int main(){
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(2);
    pq.push(5);
    pq.push(1);
    pq.push(4);

    while(!pq.empty()){
        std::cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}