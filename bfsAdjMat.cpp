#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Function to perform Breadth-First Search (BFS) on a graph represented as an adjacency matrix
void bfs(std::vector<std::vector<int>> A, int s) {
    // Vector to keep track of visited nodes
    std::vector<bool> visited(A.size(), false);
    // Queue to manage the BFS traversal
    std::queue<int> q;
    int u;

    // Start BFS from the source node `s`
    std::cout << s << ' ';
    visited[s] = true; // Mark the source node as visited
    q.push(s);         // Enqueue the source node

    // Continue until the queue is empty
    while (!q.empty()) {
        u = q.front(); // Get the front node from the queue
        q.pop();       // Remove the front node from the queue

        // Explore all neighbors of the current node `u`
        for (int v = 0; v < A.size(); v++) {
            // If there is an edge and the neighbor is not visited
            if (A[u][v] && !visited[v]) {
                std::cout << v << ' '; // Print the neighbor
                visited[v] = true;     // Mark the neighbor as visited
                q.push(v);             // Enqueue the neighbor
            }
        }
    }
}

int main() {
    // Adjacency matrix representation of the graph
    std::vector<std::vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0}, // Node 0
        {1, 0, 0, 1, 0}, // Node 1
        {1, 0, 0, 0, 1}, // Node 2
        {0, 1, 0, 0, 0}, // Node 3
        {0, 0, 1, 0, 0}  // Node 4
    };

    // Perform BFS starting from node 0
    bfs(adjMatrix, 0);
    return 0;
}