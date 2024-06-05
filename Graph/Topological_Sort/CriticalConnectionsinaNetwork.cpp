class Solution
{
public:
    int tym = 0;
    void dfs_Bridge(int node, int parent, vector<int> &in, vector<int> &low, vector<int> &vis, vector<vector<int>> &ans,
                    vector<vector<int>> &adj)
    {
        vis[node] = 1;
        in[node] = tym;
        low[node] = tym;
        tym++;
        for (auto x : adj[node])
        {
            if (x == parent)
                continue;
            if (vis[x] == 0)
            {
                dfs_Bridge(x, node, in, low, vis, ans, adj);
                low[node] = min(low[x], low[node]);
                if (low[x] > in[node])
                {
                    ans.push_back({x, node});
                }
            }
            else
            {
                low[node] = min(low[x], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto x : connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        vector<int> in(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (vis[0] == 0)
            {
                dfs_Bridge(0, -1, in, low, vis, ans, adj);
            }
        }
        return ans;
    }
};