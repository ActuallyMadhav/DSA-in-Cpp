#include <iostream>
#include <algorithm>
#include <vector>

#define base 256    // number of possible characters
#define prime 101   // a prime number for modulus

void rabinKarp(const std::string& text, const std::string& pattern){
    int n = text.size();
    int m = pattern.size();

    // precompute hash of pattern and first window of text
    int pHash = 0;
    int tHash = 0;
    int h = 1;

    // h = base ^ (m-1) % prime
    for(int i = 0; i < m-1; i++){
        h = (h * base) % prime;
    }

    // init hash values
    for(int i = 0; i < m; i++){
        pHash = (base * pHash + pattern[i]) % prime;
        tHash = (base * tHash + text[i]) % prime;
    }

    bool found = false; // flag to track matches

    // slide over text
    for(int i = 0; i < n-m+1; i++){
        // if hash matches, compare substr to pattern
        if(pHash == tHash){
            if(text.substr(i,m) == pattern){
                std::cout << "Pattern found at index: " << i << '\n';
                found = true;
            }
        }
        
        // compute hash for next window
        if(i < n-m){
            tHash = (base * (tHash - text[i] * h) + text[i+m]) % prime;
            if(tHash < 0){tHash += prime;}
        }
    }

    if(!found){
        std::cout << "Pattern not found" << '\n';
    }
}

int main(){
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";

    rabinKarp(text, pattern);
    return 0;
}