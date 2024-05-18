
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        vector<int> ans;
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while (!q.empty())
        {
            int ssd = q.front();
            q.pop();

            for (int i = 0; i < adj[ssd].size(); i++)
            {
                if (vis[adj[ssd][i]] == 0)
                {
                    vis[adj[ssd][i]] = 1;
                    q.push(adj[ssd][i]);
                }
            }
            ans.push_back(ssd);
        }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
