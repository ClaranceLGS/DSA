#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph edge structure
struct Edge {
    int destination;
    int weight;
};

// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    Edge edge1 = {dest, weight};
    Edge edge2 = {src, weight};
    graph[src].push_back(edge1);
    graph[dest].push_back(edge2);
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int vertices) {
    vector<int> key(vertices, INT_MAX);  // Key values used to pick minimum weight edge
    vector<bool> mstSet(vertices, false);  // To track vertices included in MST
    vector<int> parent(vertices, -1);  // Array to store the constructed MST

    // Priority queue to store vertices based on key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with the first vertex
    int startVertex = 0;
    key[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        // Update key value and parent index of adjacent vertices
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Create the graph
    vector<vector<Edge>> graph(vertices);

    // Add edges to the graph
    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        cout << "Enter the source, destination, and weight of edge " << i  << ": ";
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    // Find and print the MST using Prim's algorithm
    primMST(graph, vertices);

    return 0;
}