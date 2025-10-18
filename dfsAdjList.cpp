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