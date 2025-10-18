#ifndef DFS_HPP
#define DFS_HPP

#include <iostream>
#include <vector>

void dfsAdjMat(std::vector<std::vector<int>>& AdjMat, std::vector<bool>& visited, int s){
    visited[s] = true;
    std::cout << s << ' ';

    for(int v = 0; v < AdjMat.size(); v++){
        if(AdjMat[s][v] && !visited[v]){
            dfsAdjMat(AdjMat, visited, v);
        }
    }
}


void dfsAdjList(std::vector<std::vector<int>>& AdjList, std::vector<bool>& visited, int s){
    visited[s] = true;
    std::cout << s << ' ';

    for(int v : AdjList[s]){
        if(!visited[v]){
            dfsAdjList(AdjList, visited, v);
        }
    }
}

#endif