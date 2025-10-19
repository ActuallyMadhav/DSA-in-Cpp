#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

/*
instead of making custom heap class:

MAX HEAP:
    std::priority_queue<int> maxHeap;   // by default, std:priority_queue is a MAX HEAP

MIN HEAP:
    std::priority_queue<
        int,                // type of element stored in heap
        std::vector<int>    // underlying container
        std::greater<int>   // comparator to make into min heap
    >minHeap;
*/

class Heap{
    private:
        std::vector<int> heap;

        int leftChild(int index){
            // return 2*index;      // if heap is 1-indexed
            return 2*index + 1;
        }

        int rightChild(int index){
            return 2*index + 2;
        }

        int parent(int index){
            return (index-1) / 2;
        }
    
    public:
        void printHeap(){
            std::cout << "\n[";
            for(size_t i = 0; i < heap.size(); i++){
                std::cout << heap[i];
                if(i < heap.size()-1){std::cout << ", ";}
            }
            std::cout << ']' << '\n';
        }

        void insert(int value){
            heap.push_back(value);
            int cur = heap.size()-1;

            while(cur > 0 && heap[cur] > heap[parent(cur)]){
                std::swap(heap[cur], heap[parent(cur)]);
                cur = parent(cur);
            }
        }

        void sinkDown(int index){
            int maxIndex = index;

            while(true){
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);

                if(leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]){
                    maxIndex = leftIndex;
                }

                if(rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]){
                    maxIndex = rightIndex;
                }

                if(maxIndex != index){
                    std::swap(heap[maxIndex], heap[index]);
                    index = maxIndex;
                }
                else{
                    return;
                }
            }
        }

        int remove(){
            if(heap.empty()) return INT_MIN;

            int maxValue = heap.front();

            if(heap.size() == 1){
                heap.pop_back();
            }
            else{
                heap[0] = heap.back();
                heap.pop_back();
                sinkDown(0);
            }

            return maxValue;
        }

        std::vector<int> heapSort(){
            std::vector<int> sorted;
            std::vector<int> original = heap;

            while(!heap.empty()){
                sorted.push_back(remove());
            }

            std::reverse(sorted.begin(), sorted.end()); // makes into ascending order

            heap = original;
            return sorted;
        }
};

int main(){
    Heap* myHeap = new Heap();

    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);

    myHeap->printHeap();

    myHeap->insert(100);
    myHeap->printHeap();

    myHeap->insert(75);
    myHeap->printHeap();

    myHeap->remove();
    myHeap->printHeap();

    myHeap->remove();
    myHeap->printHeap();

    std::vector<int> sorted = myHeap->heapSort();
    for(int x : sorted){std::cout << x << ' ';}
    std::cout << '\n';
}