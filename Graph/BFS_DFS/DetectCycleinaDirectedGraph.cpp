class Solution
{
public:
    bool dfs(int node, vector<int> &vis, vector<int> &path, vector<int> adj[])
    {
        vis[node] = 1;
        path[node] = 1;
        for (auto x : adj[node])
        {
            if (vis[x] == 0)
            {
                if (dfs(x, vis, path, adj))
                {
                    return true;
                }
            }
            else if (vis[x] == 1 && path[x] == 1)
            {
                return true;
            }
        }
        path[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, vis, path, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};