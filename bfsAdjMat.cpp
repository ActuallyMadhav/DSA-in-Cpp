#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(std::vector<std::vector<int>> A, int s){
    std::vector<bool> visited(A.size(), false);
    std::queue<int> q;
    int u;

    std::cout << s << ' ';
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int v = 0; v < A.size(); v++){
            if(A[u][v] && !visited[v]){
                std::cout << v << ' ';
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){

    std::vector<std::vector<int>> adjMatrix = {
    {0, 1, 1, 0, 0}, // Node 0
    {1, 0, 0, 1, 0}, // Node 1
    {1, 0, 0, 0, 1}, // Node 2
    {0, 1, 0, 0, 0}, // Node 3
    {0, 0, 1, 0, 0}  // Node 4
    };

    bfs(adjMatrix, 0);
    return 0;
}