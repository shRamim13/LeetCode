
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function Template for C++

// class Solution
// {
// private:
//     int timer = 1;
//     void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
//              vector<int> &mark, vector<int> adj[])
//     {
//         vis[node] = 1;
//         tin[node] = low[node] = timer;
//         timer++;
//         int child = 0;
//         for (auto it : adj[node])
//         {
//             if (it == parent)
//                 continue;
//             if (!vis[it])
//             {
//                 dfs(it, node, vis, tin, low, mark, adj);
//                 low[node] = min(low[node], low[it]);
//                 if (low[it] >= tin[node] && parent != -1)
//                 {
//                     mark[node] = 1;
//                 }
//                 child++;
//             }
//             else
//             {
//                 low[node] = min(low[node], tin[it]);
//             }
//         }
//         if (child > 1 && parent == -1)
//         {
//             mark[node] = 1;
//         }
//     }

// public:
//     vector<int> articulationPoints(int n, vector<int> adj[])
//     {
//         vector<int> vis(n, 0);
//         int tin[n];
//         int low[n];
//         vector<int> mark(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             if (!vis[i])
//             {
//                 dfs(i, -1, vis, tin, low, mark, adj);
//             }
//         }
//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//         {
//             if (mark[i] == 1)
//             {
//                 ans.push_back(i);
//             }
//         }
//         if (ans.size() == 0)
//             return {-1};
//         return ans;
//     }
// };

// //{ Driver Code Starts.

// int main()
// {
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int V, E;
//         cin >> V >> E;
//         vector<int> adj[V];
//         for (int i = 0; i < E; i++)
//         {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         Solution obj;
//         vector<int> ans = obj.articulationPoints(V, adj);
//         for (auto i : ans)
//             cout << i << " ";
//         cout << "\n";
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <random>

std::vector<int> generateRandomNumbers(int n, int minValue, int maxValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);

    std::vector<int> randomNumbers;
    randomNumbers.reserve(n);

    for (int i = 0; i < n; ++i) {
        randomNumbers.push_back(dis(gen));
    }

    return randomNumbers;
}

int main() {
    int n = 10000;
    int minValue = 0;
    int maxValue = 999;

    std::vector<int> randomNumbers = generateRandomNumbers(n, minValue, maxValue);

    // Print the generated random numbers as a single line, comma-separated
    for (int i = 0; i < randomNumbers.size(); ++i) {
        std::cout << randomNumbers[i];
        if (i != randomNumbers.size() - 1) {
            std::cout << ", ";
        }
    }

    return 0;
}
