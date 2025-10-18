#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Function to perform Breadth-First Search (BFS) on a graph
// A: Adjacency list representation of the graph
// s: Starting node for BFS
void bfs(std::vector<std::vector<int>>& A, int s){
    int n = A.size(); // Number of nodes in the graph
    std::vector<bool> visited(n, false); // To keep track of visited nodes
    std::queue<int> q; // Queue to manage the BFS traversal

    visited[s] = true; // Mark the starting node as visited
    q.push(s); // Enqueue the starting node

    while(!q.empty()){ // Continue until the queue is empty
        int u = q.front(); // Get the front node in the queue
        q.pop(); // Remove the front node from the queue
        std::cout << u << ' '; // Print the current node

        // Traverse all neighbors of the current node
        for(int v : A[u]){
            if(!visited[v]){ // If the neighbor is not visited
                visited[v] = true; // Mark it as visited
                q.push(v); // Enqueue the neighbor
            }
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

    bfs(adjList, 0);
    return 0;
}