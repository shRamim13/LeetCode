class Solution
{
public:
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &graph, int &flag)
    {
        vis[node] = 1;
        for (auto x : graph[node])
        {
            if (x == parent)
            {
                continue;
            }
            if (vis[x] == 0)
            {
                dfs(x, node, vis, graph, flag);
            }
            else if (vis[x] == 1)
            {
                flag = 1;
            }
        }
    }

    bool validTree(int n, vector<vector<int>> &edges)
    {
        int e = edges.size();
        int flag = 0;
        if (n != e + 1)
        {
            return false;
        }
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);
        for (auto x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                dfs(i, -1, vis, graph, flag);
            }
            if (cnt > 1 || flag == 1)
            {
                return false;
            }
        }
        return true;
    }
};
