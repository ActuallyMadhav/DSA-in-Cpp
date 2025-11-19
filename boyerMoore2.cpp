#include <iostream>
#include <vector>

// helper function
std::vector<int> buildLastFunction(const std::string& pattern){
    const int N_ASCII = 128;    // number of ascii chars

    std::vector<int> last(N_ASCII); // assume ascii char set

    for(int i = 0; i < N_ASCII; i++){
        last[i] = -1;   // init array elements to -1
    }

    for(int i = 0; i < pattern.size(); i++){
        last[pattern[i]] = i;   // implicit cast to ascii code
    }
    return last;
}

int boyerMoore(const std::string& text, const std::string& pattern){
    std::vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1;

    if(i > n-1) return -1;  // pattern longer than text -> no match

    int j = m - 1;

    do{
        if(pattern[j] == text[i]){
            if(j == 0) return 0; // found a match
            else{   // looking glass heuristic
                i--;    // proceed right to left
                j--;
            }
        }
        else{   // character jump heuristic
            i = i + m - std::min(j, 1 + last[text[i]]);
            j = m - 1;
        }
    }while(i <= n - 1);
    return -1;  // no match
}