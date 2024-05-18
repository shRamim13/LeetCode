#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            int adjNode = adj[node][i];
            if (vis[adjNode] == 0)
            {
                dfs(adjNode, vis, adj, ans);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<int> vis(V, 0);
        dfs(0, vis, adj, ans);
        return ans;
    }
};

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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}