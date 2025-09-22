#include <iostream>
#include <algorithm>
#include <vector>
#include "binarySearch.h"

int main(){
    std::vector<std::string> movies = {"conjuring", "toy story", "Dhoom", "Dhoom 2"};
    std::string targetMovie = "toy story 2";
    std::sort(movies.begin(), movies.end());
    double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Target float found at location: " << binarySearch(arr, 5, 2.2) << '\n';
    std::cout << "Target movie found at location: " << binarySearch(movies, targetMovie) << '\n';

    return 0;
}