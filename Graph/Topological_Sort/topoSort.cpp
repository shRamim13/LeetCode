// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
class Solution
{
private:
    void dfsTopo(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
    {
        vis[node] = 1;
        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                dfsTopo(x, vis, adj, ans);
            }
        }
        ans.push_back(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfsTopo(i, vis, adj, ans);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// int check(int V, vector<int> &res, vector<int> adj[])
// {

//     if (V != res.size())
//         return 0;

//     vector<int> map(V, -1);
//     for (int i = 0; i < V; i++)
//     {
//         map[res[i]] = i;
//     }
//     for (int i = 0; i < V; i++)
//     {
//         for (int v : adj[i])
//         {
//             if (map[i] > map[v])
//                 return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int N, E;
//         cin >> E >> N;
//         int u, v;

//         vector<int> adj[N];

//         for (int i = 0; i < E; i++)
//         {
//             cin >> u >> v;
//             adj[u].push_back(v);
//         }

//         Solution obj;
//         vector<int> res = obj.topoSort(N, adj);

//         cout << check(N, res, adj) << endl;
//     }

//     return 0;
// }