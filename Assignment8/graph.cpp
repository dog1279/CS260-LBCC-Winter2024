#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define structure for vertices
struct Vertex
{
    int id;
    vector<pair<int, int>> edges; // pair: (destination, weight)
    bool visited;
    Vertex(int id) : id(id), visited(false) {}
};

class Graph
{
private:
    vector<Vertex> vertices;

public:
    // Function to add a new vertex to the graph
    void add_vertex(int vertex_name)
    {
        vertices.emplace_back(vertex_name);
    }

    // Function to add a new edge between two vertices
    void add_edge(int source, int destination, int weight)
    {
        vertices[source].edges.emplace_back(destination, weight);
        // For undirected graph, uncomment the line below
        // vertices[destination].edges.emplace_back(source, weight);
    }

    // Function for shortest path algorithm (Dijkstra's Algorithm)
    vector<int> shortest_path(int source, int destination)
    {
        vector<int> dist(vertices.size(), INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto edge : vertices[u].edges)
            {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    // Function for minimum spanning tree algorithm (Prim's Algorithm)
    vector<pair<int, int>> min_span_tree()
    {
        vector<pair<int, int>> mst; // Store minimum spanning tree edges (destination, weight)
        vector<bool> in_mst(vertices.size(), false);
        vector<int> key(vertices.size(), INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // Start with vertex 0

        key[0] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            in_mst[u] = true;

            for (auto edge : vertices[u].edges)
            {
                int v = edge.first;
                int weight = edge.second;

                if (!in_mst[v] && key[v] > weight)
                {
                    key[v] = weight;
                    pq.push({weight, v});
                    mst.emplace_back(u, v);
                }
            }
        }

        return mst;
    }
};

int main()
{
    // Test the Graph class
    Graph g;

    // Add vertices
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    // Add edges
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 2);
    g.add_edge(2, 3, 4);

    // Test shortest path algorithm
    vector<int> shortest_dist = g.shortest_path(0, 3);
    cout << "Shortest distances from source (0) to all vertices:\n";
    for (int i = 0; i < shortest_dist.size(); ++i)
    {
        cout << "Vertex " << i << ": " << shortest_dist[i] << "\n";
    }

    // Test minimum spanning tree algorithm
    vector<pair<int, int>> mst_edges = g.min_span_tree();
    cout << "\nMinimum Spanning Tree Edges:\n";
    for (auto edge : mst_edges)
    {
        cout << edge.first << " - " << edge.second << "\n";
    }

    return 0;
}
