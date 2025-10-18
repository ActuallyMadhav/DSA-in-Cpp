#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& AdjList, std::vector<bool>& visited, int s){
    visited[s] = true;
    std::cout << s << ' ';

    for(int v : AdjList[s]){
        if(!visited[v]){
            dfs(AdjList, visited, v);
        }
    }
}

int main(){

    std::vector<std::vector<int>> adjList = {
        {1, 2},    // Node 0
        {0, 3},    // Node 1
        {0, 4},    // Node 2
        {1},       // Node 3
        {2}        // Node 4
    };

    std::vector<bool> visited(adjList.size(), false);

    dfs(adjList, visited, 0);
    return 0;
}