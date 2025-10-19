#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::vector<int> dijkstra(std::vector<std::vector<int>>& A, int s){
    int V = A.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false);

    dist[s] = 0;

    for(int count = 0; count < V-1; count++){
        int u = -1;
        for(int i = 0; i < V; i++){
            if(!visited[i] && (u == -1 || dist[i] < dist[u])){
                u = i;
            }
        }

        if(u == -1) break; // all other nodes are unreachable

        visited[u] = true;

        for(int v = 0; v < V; v++){
            if(!visited[v] && A[u][v] != INT_MAX){
                if(dist[u] + A[u][v] < dist[v]){
                    dist[v] = dist[u] + A[u][v];
                }
            }
        }
    }

    return dist;
}

void printDist(std::vector<int> dist){
    for(int i = 0; i < dist.size(); i++){
        std::cout << "Distance to node " << i << ": " << dist[i] << '\n';
    }
}

int main(){

    std::vector<std::vector<int>> adjMat = {
        {INT_MAX,1,5,INT_MAX,INT_MAX,INT_MAX},
        {1,INT_MAX,3,10,8,INT_MAX},
        {5,3,INT_MAX,INT_MAX,2,INT_MAX},
        {INT_MAX,10,INT_MAX,INT_MAX,3,2},
        {INT_MAX,8,2,3,INT_MAX,7},
        {INT_MAX,INT_MAX,INT_MAX,2,7,INT_MAX}

    };

    std::vector<int> dist = dijkstra(adjMat, 0);
    printDist(dist);
    return 0;
}