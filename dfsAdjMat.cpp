#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& A, std::vector<bool>& visited, int s){
    int n = A.size();

    visited[s] = true;
    std::cout << s << ' ';

    for(int v = 0; v < n; v++){
        if(A[s][v] && !visited[v]){
            dfs(A,visited, v);
        }
    }
}