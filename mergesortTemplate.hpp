#ifndef MERGESORTTEMPLATES_HPP
#define MERGESORTTEMPLATES_HPP

#include <iostream>
#include <vector>
#include <algorithm>

///////////////////////////////////// STD::VECTOR (DYNAMIC ARRAY) ///////////////////////////////
template <typename T>
void merge(std::vector<T>& arr, std::vector<T>& left, std::vector<T>& right);

template <typename T>
void mergeSort(std::vector<T>& arr);

///////////////////////////////////// C-STYLE ARRAY ///////////////////////////////
template <typename T>
void merge(T* arr, T* left, T* right, int leftSize, int rightSize);

template <typename T>
void mergeSort(T* arr, int size);

///////////////////////////////////// STD::VECTOR (DYNAMIC ARRAY) ///////////////////////////////
template <typename T>
void merge(std::vector<T>& arr, std::vector<T>& left, std::vector<T>& right){
    int leftSize = left.size();
    int rightSize = right.size();

    int i,j,k;
    i = j = k = 0;

    while(i < leftSize && j < rightSize){
        if(left[i] < right[j]){arr[k++] = left[i++];}
        else{arr[k++] = right[j++];}
    }

    while(i < leftSize){arr[k++] = left[i++];}
    while(j < rightSize){arr[k++] = right[j++];}
}

template <typename T>
void mergeSort(std::vector<T>& arr){
    int n = arr.size();
    if(n < 2) return;

    int mid = n / 2;

    std::vector<T> left(mid);
    std::vector<T> right(n - mid);

    for(int i = 0; i < n; i++){
        if(i < mid){left[i] = arr[i];}
        else{right[i - mid] = arr[i];}
    }

    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
}

///////////////////////////////////// C-STYLE ARRAY ///////////////////////////////
template <typename T>
void merge(T* arr, T* left, T* right, int leftSize, int rightSize){
    int i,j,k;
    i = j = k = 0;

    while(i < leftSize && j < rightSize){
        if(left[i] < right[j]){arr[k++] = left[i++];}
        else{arr[k++] = right[j++];}
    }

    while(i < leftSize){arr[k++] = left[i++];}
    while(j < rightSize){arr[k++] = right[j++];}
}

template <typename T>
void mergeSort(T* arr, int size){
    if(size < 2) return;
    int mid = size/2;

    T* left = new T[mid];
    T* right = new T[size-mid];

    for(int i = 0; i < size; i++){
        if(i < mid){left[i] = arr[i];}
        else{right[i-mid] = arr[i];}
    }

    mergeSort(left, mid);
    mergeSort(right, size-mid);
    merge(arr, left, right, mid, size-mid);

    delete[] left;
    delete[] right;
}

#endif