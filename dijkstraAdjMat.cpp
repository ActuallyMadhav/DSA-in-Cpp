#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::pair<std::vector<int>, std::vector<int>> dijkstra(const std::vector<std::vector<int>>& A, int s){
    int V = A.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false);
    std::vector<int> pi(V, -1);

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
                    pi[v] = u;
                }
            }
        }
    }

    return {dist, pi};
}

void printDist(std::vector<int> dist){
    for(int i = 0; i < dist.size(); i++){
        std::cout << "Distance to node " << i << ": " << dist[i] << '\n';
    }
}

void printPath(int target, const std::vector<int>& pi){
    if(pi[target] == -1){
        std::cout << target;
        return;
    }
    printPath(pi[target], pi);
    std::cout << " -> " << target;
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

    std::pair<std::vector<int>, std::vector<int>> result = dijkstra(adjMat, 0);
    std::vector<int> dist = result.first;
    std::vector<int> pi = result.second;
    printDist(dist);

    for(int i = 0; i < pi.size(); i++){
        std::cout << "Path to node: " << i << ": ";
        if(dist[i] == INT_MAX){
            std::cout << "UNREACHABLE" << '\n';
        }
        else{
            printPath(i, pi);
            std::cout << '\n';
        }
    }
    return 0;
}