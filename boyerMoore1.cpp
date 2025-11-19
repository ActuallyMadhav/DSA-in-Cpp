#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> boyerMoore(const std::string& text, const std::string& pattern){
    int m = pattern.size();
    int n = text.size();

    std::unordered_map<char, int> badChar;

    // build bad character table
    for(int i = 0; i < m; i++){
        badChar[pattern[i]] = i;
    }

    std::vector<int> result;
    int shift = 0;

    while(shift <= n - m){
        int j = m-1;

        // compare from right to left
        while(j >= 0 && pattern[j] == text[shift+j]){
            j--;
        }

        if(j < 0){
            result.push_back(shift);    // found a match

            if(shift + m < n){
                char nextChar = text[shift+m];
                auto it = badChar.find(nextChar);
                int lastIdx = (it != badChar.end()) ? it->second : -1;
                shift += m - lastIdx;
            }
            else{
                shift++;
            }
        }
        else{
            // mismatch -> use bad character rule
            char bad = text[shift + j];
            auto it = badChar.find(bad);
            int lastIdx = (it != badChar.end()) ? it->second : -1;
            shift += std::max(1, j-lastIdx);
        }
    }

    return result;
}

int main() {
    std::string text = "abacaabadcabacaba";
    std::string pattern = "aba";

    std::vector<int> matches = boyerMoore(text, pattern);

    for (int idx : matches) {
        std::cout << "Pattern found at index " << idx << "\n";
    }
    return 0;
}
