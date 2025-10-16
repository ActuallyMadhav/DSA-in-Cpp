#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void heapify(std::vector<T>& arr, int n, int i);

template <typename T>
void heapSort(std::vector<T>& arr);

int main(){
    std::vector<int> data = {4, 10, 3, 5, 1};
    heapSort(data);

    for (int num : data)
        std::cout << num << " ";

    return 0;
}

template <typename T>
void heapify(std::vector<T>& arr, int n, int i){
    int largest = i;        // initialize largest as root
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child

    // if left child > root
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    // if right child > root
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    // if largest is not root
    if(largest != i){
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);   // recursively heapify affected subtree
    }
}

template <typename T>
void heapSort(std::vector<T>& arr){
    int n = arr.size();

    // build max heap
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    // extract elements one by one from heap
    for(int i = n-1; i > 0; i--){
        std::swap(arr[0], arr[i]);      // move current root to end
        heapify(arr, i, 0);             // heapify reduced heap
    }
}