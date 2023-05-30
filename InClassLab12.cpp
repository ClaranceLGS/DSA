#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // Infinity value for unreachable nodes

vector<int> dijkstra(int n, vector<vector<int>>& graph, int start) {
    vector<int> distances(n, INF); // Distances from the start city
    vector<bool> visited(n, false); // Visited array to track visited nodes

    distances[start] = 0;

    for (int i = 0; i < n; i++) {
        int minDist = INF;
        int minNode = -1;

        // Find the node with the minimum distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distances[j] < minDist) {
                minDist = distances[j];
                minNode = j;
            }
        }

        // Mark the current node as visited
        visited[minNode] = true;

        // Update the distances of the neighboring nodes
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[minNode][j] != INF && distances[minNode] + graph[minNode][j] < distances[j]) {
                distances[j] = distances[minNode] + graph[minNode][j];
            }
        }
    }

    return distances;
}

int main() {
    int n = 6; // Number of cities

    // Initialize the adjacency matrix with INF (representing no edge)
    vector<vector<int>> graph(n, vector<int>(n, INF));

    // Add edges to the graph (average time between cities)
    graph[0][1] = 10;
    graph[0][4] = 15;
    graph[0][5] = 5;
    graph[1][0] = 10;
    graph[1][2] = 10;
    graph[1][3] = 30;
    graph[2][1] = 10;
    graph[2][3] = 12;
    graph[2][4] = 5;
    graph[3][1] = 30;
    graph[3][2] = 12;
    graph[3][5] = 20;
    graph[4][0] = 15;
    graph[4][2] = 5;
    graph[5][0] = 5;
    graph[5][3] = 20;

    

    int start = 5; // Source city

    vector<int> result = dijkstra(n, graph, start);

    // Print the shortest times from the start city to all other cities
    for (int i = 0; i < n; i++) {
        if (i != start) {
            cout << "Shortest time from City " << start << " to City " << i << ": " << result[i] << endl;
        }
    }

    return 0;
}
