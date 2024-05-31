vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // Initialize adjacency list
    vector<vector<int>> adj(N);
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize distance vector with a large value
    vector<int> distance(N, 1e9);
    vector<bool> visited(N, false);
    queue<int> q;

    // BFS initialization
    q.push(src);
    distance[src] = 0;
    visited[src] = true;

    // BFS execution
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                distance[neighbor] = distance[node] + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Prepare the answer vector
    vector<int> result(N, -1);
    for (int i = 0; i < N; ++i)
    {
        if (distance[i] != 1e9)
        {
            result[i] = distance[i];
        }
    }

    return result;
}