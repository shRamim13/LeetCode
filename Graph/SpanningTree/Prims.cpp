#include <bits/stdc++.h>
using namespace std;

pair<int, vector<pair<int, int>>> spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int cst = 0;
    vector<pair<int, int>> mst_edges;

    while (!pq.empty())
    {
        auto ssd = pq.top();
        int node = ssd.second;
        int dis = ssd.first;
        pq.pop();

        if (vis[node] == 1)
        {
            continue;
        }

        vis[node] = 1;
        cst += dis;
        if (dis > 0)
        {
            mst_edges.push_back({ssd.second, node});
        }

        for (auto x : adj[node])
        {
            int nxtNode = x[0];
            int nxtDis = x[1];
            if (vis[nxtNode] == 0)
            {
                pq.push({nxtDis, nxtNode});
            }
        }
    }
    return {cst, mst_edges};
}

int main()
{
    int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({2, 7});

    auto result = spanningTree(V, adj);
    int cost = result.first;
    vector<pair<int, int>> mst_edges = result.second;

    cout << "Cost of MST: " << cost << endl;
    cout << "Edges in MST:" << endl;
    for (auto edge : mst_edges)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
