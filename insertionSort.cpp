#include <iostream>
#include <algorithm>

void insertionSort(int* A, int size){   // can use "int A[]" as parameter as well
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0; j--){
            if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
            }
        }
    }
}

////////////// ALTERNATIVE INSERTION SORT//////////////////
void insertionSort2(int* A, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int x = A[i];

        while(j > -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
///////////////////////////////////////////////////////////

int main(){
    int a[5] = {3,4,1,2,5};

    insertionSort(a, 5);
    for(int x : a){
        std::cout << x << ' ';
    }

    std::cout << '\n';

    int b[5] = {4,1,2,5,6};
    insertionSort2(b,5);
    for(int x : b){
        std::cout << x << ' ';
    }
    
    return 0;
}