//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    // bool bfsCycle(int node, vector<int>& vis, vector<int> adj[]) {
    //         queue<pair<int, int>> pq;
    //         pq.push({node, -1});
    //         vis[node] = 1;

    //         while (!pq.empty()) {
    //             int nd = pq.front().first;
    //             int pr = pq.front().second;
    //             pq.pop();

    //             for (auto x : adj[nd]) {
    //                 if (vis[x] == 0) {
    //                     vis[x] = 1;
    //                     pq.push({x, nd});
    //                 } else if (x != pr) {
    //                     return true;
    //                 }
    //             }
    //         }
    //         return false;
    //     }

private:
    bool dfsCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto x : adj[node])
        {
            if (vis[x] == 0)
            {
                if (dfsCycle(x, node, vis, adj))
                {
                    return true;
                }
            }
            else if (vis[x] == 1 && parent != x)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfsCycle(i, -1, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}