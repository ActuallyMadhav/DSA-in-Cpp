#include <iostream>
#include <algorithm>
#include <vector>

int stringMatch(const std::string& inputStr, const std::string& pattern){
    int n = inputStr.size();
    int m = pattern.size();

    std::vector<int> indices;

    // try every possible starting index
    for(int i = 0; i <= n - m; i++){
        int j = 0;
        
        // compare pattern with substrs of inputStr
        while(j < m && inputStr[i+j] == pattern[j]){
            j++;
        }
        if(j == m){
            return i; // match found at index i
        }
    }
    return -1; // match not found
}