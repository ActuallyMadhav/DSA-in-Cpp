#include <iostream>
#include <algorithm>
#include <vector>

// int stringMatch(const std::string& inputStr, const std::string& pattern){
//     int n = inputStr.size();
//     int m = pattern.size();

//     std::vector<int> indices;

//     // try every possible starting index
//     for(int i = 0; i <= n - m; i++){
//         int j = 0;
        
//         // compare pattern with substrs of inputStr
//         while(j < m && inputStr[i+j] == pattern[j]){
//             j++;
//         }
//         if(j == m){
//             return i; // match found at index i
//         }
//     }
//     return -1; // match not found
// }

// alternatively:

int bruteForceMatch(std::string text, std::string pattern){
    int textSize = text.size();
    int patternSize = pattern.size();

    for(int i = 0; i <= textSize - patternSize; i++){
        int j = 0;

        while(j < patternSize && text[i + j] == pattern[j]){
            j++;
        }
        if(j == patternSize) return i;
    }
    return -1;  // no match found
}

int main(){
    std::string substr = "hello";
    std::string text = "hi hello bye bye";

    int pos = bruteForceMatch(text, substr);

    (pos == -1) ? std::cout << "Substring not found" << '\n' : std::cout << "Subtring found at " << pos << '\n';
    return 0;
}