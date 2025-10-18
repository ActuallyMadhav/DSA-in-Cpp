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

int main() {
    // Adjacency matrix representation of the graph
    std::vector<std::vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0}, // Node 0
        {1, 0, 0, 1, 0}, // Node 1
        {1, 0, 0, 0, 1}, // Node 2
        {0, 1, 0, 0, 0}, // Node 3
        {0, 0, 1, 0, 0}  // Node 4
    };

    std::vector<bool> visited(adjMatrix.size(), 0);

    // Perform DFS starting from node 0
    dfs(adjMatrix, visited, 0);
    return 0;
}