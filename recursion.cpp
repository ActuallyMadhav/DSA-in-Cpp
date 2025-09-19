#include <iostream>

void fun1(int n){
    if(n > 0){
        std::cout << n;
        fun1(n-1);
    }
    // output: n n-1 n-2 ... 3 2 1
}

void fun2(int n){
    if(n > 0){
        fun2(n-1);
        std::cout << n;
    }
    // output: 1 2 3 ... n-2 n-1 n
}

int main(){

    fun1(3);
    std::cout << '\n';
    fun2(3);

    return 0;
}