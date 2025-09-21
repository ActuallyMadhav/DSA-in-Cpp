#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
#include <vector>

template <typename T> 
int binarySearch(const std::vector<T>& arr, T target){
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) return mid;

        else if(arr[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

template <typename T>
int binarySearch(T* arr, int size, T target){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = left + (right- left) / 2;

        if(arr[mid] == target) return mid;

        else if(arr[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

#endif