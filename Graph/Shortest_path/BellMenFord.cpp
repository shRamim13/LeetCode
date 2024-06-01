#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<long long> bellmanFord(int n, vector<vector<int>> &edges, int src)
    {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            for (const auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
            {
                // If a shorter path is found, then there is a negative cycle
                cout << "Graph contains negative weight cycle" << endl;
                return {};
            }
        }

        return dist;
    }
};

int main()
{
    Solution solution;
    int n = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int src = 0; // Source vertex
    vector<long long> distances = solution.bellmanFord(n, edges, src);

    if (!distances.empty())
    {
        for (int i = 0; i < distances.size(); ++i)
        {
            cout << "Distance from node " << src << " to node " << i << " is " << distances[i] << endl;
        }
    }

    return 0;
}
