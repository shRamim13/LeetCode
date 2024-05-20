#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (adj[node][i] == 1 && vis[i] == 0)
            {
                dfs(i, vis, adj);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> &adj, int V)
    {
        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}