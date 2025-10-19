#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> dijkstra(const std::vector<std::vector<std::pair<int,int>>>& A, int s){
    int V = A.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> visited(V, false);
    std::vector<int> pi(V, -1);

    // priority queue -> min heap
    std::priority_queue<
        std::pair<int, int>,                // type of element stored: pairs of {distance, vertex}
        std::vector<std::pair<int,int>>,    // underlying container
        std::greater<>                      // comparator
    > pq;

    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()){
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if(d_u > dist[u]) continue;

        for(const auto& edge : A[u]){
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                pi[v] = u;
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

    std::vector<std::vector<std::pair<int, int>>> adjList = {
        {{1, 1}, {2, 5}},                // Node 0
        {{0, 1}, {2, 3}, {3, 10}, {4, 8}}, // Node 1
        {{0, 5}, {1, 3}, {4, 2}},        // Node 2
        {{1, 10}, {4, 3}, {5, 2}},       // Node 3
        {{1, 8}, {2, 2}, {3, 3}, {5, 7}}, // Node 4
        {{3, 2}, {4, 7}}                 // Node 5
    };

    std::pair<std::vector<int>, std::vector<int>> result = dijkstra(adjList, 0);

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