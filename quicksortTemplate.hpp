#ifndef QUICKSORTTEMPLATE_HPP
#define QUICKSORTTEMPLATE_HPP

#include <iostream>
#include <vector>
#include <algorithm>

// Partition function for std::vector
// Rearranges elements around a pivot such that elements less than pivot are on the left,
// and elements greater than pivot are on the right. Returns the final pivot index.

///////////////////////////////////// STD::VECTOR (DYNAMIC ARRAY) ///////////////////////////////
template <typename T>
int partition(std::vector<T>& arr, int left, int right);

template <typename T>
void quicksort(std::vector<T>& arr, int left, int right);

///////////////////////////////////// C-STYLE ARRAY ///////////////////////////////
template <typename T>
int partition(T* arr, int left, int right);

template <typename T>
void quicksort(T* arr, int left, int right);

///////////////////////////////////// STD::VECTOR (DYNAMIC ARRAY) ///////////////////////////////
template <typename T>
int partition(std::vector<T>& arr, int left, int right){
    T pivot = arr[right];       // Choose the last element as pivot
    int i = left - 1;           // i tracks the position for swapping smaller elements

    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[j], arr[i]);  // Move smaller element to the left partition
        }
    }
    i++;
    std::swap(arr[i], arr[right]);  // Place pivot in its correct sorted position
    return i;   // Return pivot index
}

template <typename T>
void quicksort(std::vector<T>& arr, int left, int right){
    if(right <= left) return;   // base case -> alr sorted

    int pivot = partition(arr, left, right);    // partition array
    quicksort(arr, left, pivot - 1);            // recursively sort left
    quicksort(arr, pivot + 1, right);           // recursively sort
}

///////////////////////////////////// C-STYLE ARRAY ///////////////////////////////
template <typename T>
int partition(T* arr, int left, int right){
    T pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[j], arr[i]);
        }
    }
    i++;
    std::swap(arr[i], arr[right]);
    return i;
}

template <typename T>
void quicksort(T* arr, int left, int right){
    if(right <= left) return;

    int pivot = partition(arr, left, right);
    quicksort(arr, left, pivot - 1);
    quicksort(arr, pivot + 1, right);
}

#endif