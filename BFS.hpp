#ifndef BFS_HPP
#define BFS_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfsAdjMat(std::vector<std::vector<int>>& AdjMat, int s){
    int n = AdjMat.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    std::cout << s << ' ';
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++){
            if(AdjMat[u][v] && !visited[v]){
                std::cout << v << ' ';
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void bfsAdjList(std::vector<std::vector<int>>& AdjList, int s){
    int n = AdjList.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        std::cout << u << ' ';

        for(int v : AdjList[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

#endif BFS_HPP