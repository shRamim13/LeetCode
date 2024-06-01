#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<vector<long long>> floydWarshall(int n, vector<vector<int>> &edges)
    {
        // Initialize the distance matrix
        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));

        // Set the diagonal to 0
        for (int i = 0; i < n; ++i)
        {
            dist[i][i] = 0;
        }

        // Set the initial distances based on the input edges
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Detect negative weight cycles
        for (int i = 0; i < n; ++i)
        {
            if (dist[i][i] < 0)
            {
                cout << "Graph contains a negative weight cycle" << endl;
                return {};
            }
        }

        return dist;
    }
};

int main()
{
    Solution solution;
    int n = 4; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 5}, {0, 3, 10}, {1, 2, 3}, {2, 3, 1}, {3, 1, -2}};

    vector<vector<long long>> distances = solution.floydWarshall(n, edges);

    if (!distances.empty())
    {
        for (int i = 0; i < distances.size(); ++i)
        {
            for (int j = 0; j < distances[i].size(); ++j)
            {
                if (distances[i][j] == LLONG_MAX)
                {
                    cout << "X ";
                }
                else
                {
                    cout << distances[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
