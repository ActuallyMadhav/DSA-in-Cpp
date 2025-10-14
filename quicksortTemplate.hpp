#ifndef QUICKSORTTEMPLATE_HPP
#define QUICKSORTTEMPLATE_HPP

#include <iostream>
#include <vector>
#include <algorithm>

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
void quicksort(std::vector<T>& arr, int left, int right){
    if(right <= left) return;

    int pivot = partition(arr, left, right);
    quicksort(arr, left, pivot - 1);
    quicksort(arr, pivot + 1, right);
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