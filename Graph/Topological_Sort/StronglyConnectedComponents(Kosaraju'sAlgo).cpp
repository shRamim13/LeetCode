#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs_1(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                dfs_1(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    void dfs_2(int node, vector<int> &vis, vector<vector<int>> &rev, vector<int> &component)
    {
        vis[node] = 1;
        component.push_back(node); // Store the node in the current component
        for (auto it : rev[node])
        {
            if (vis[it] == 0)
            {
                dfs_2(it, vis, rev, component);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs_1(i, vis, st, adj);
            }
        }

        // Construct the transpose of the graph
        vector<vector<int>> rev(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                rev[it].push_back(i);
            }
        }

        vector<vector<int>> components;
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (vis[x] == 0)
            {
                vector<int> component;
                dfs_2(x, vis, rev, component);
                components.push_back(component);
            }
        }
        return components.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
