#include <iostream>
#include <vector>
#include <algorithm>
#include "DisjointSet.cpp"

std::pair<int, std::vector<std::vector<int>>> kruskal(const std::vector<std::vector<int>>& edges, int n) {
    std::vector<std::vector<int>> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), [](const auto& a, const auto& b) {
        return a[2] < b[2]; // Sort by weight
    });

    DisjointSet ds(n);
    std::vector<std::vector<int>> mst;
    int minCost = 0, edgeCount = 0;

    for (const auto& edge : sortedEdges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            mst.push_back({u, v, weight});
            minCost += weight;
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }

    return {minCost, mst};
}

int main(){

    std::vector<std::vector<int>> edges = {
        {0,1,28},
        {1,6,10},
        {2,3,16},
        {2,7,14},
        {3,4,12},
        {4,5,22},
        {4,7,18},
        {5,6,25},
        {5,7,24}
    };

    int minCost = kruskal(edges, 7).first;

    std::cout << "Min Cost: " << minCost << '\n';


    return 0;
}