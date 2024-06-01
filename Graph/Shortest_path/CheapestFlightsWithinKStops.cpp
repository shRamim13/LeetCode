class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            graph[u].push_back({v, w});
        }
        vector<int> dis(n, 1e9);
        queue<pair<int, int>> q;
        q.push({src, 0});
        dis[src] = 0;
        int step = 0;
        while (!q.empty() && step <= k)
        {
            int sz = q.size();
            while (sz--)
            {
                auto [node, wt] = q.front();
                q.pop();
                for (auto [nxtNode, nxtWt] : graph[node])
                {
                    if (wt + nxtWt < dis[nxtNode])
                    {
                        dis[nxtNode] = wt + nxtWt;
                        q.push({nxtNode, dis[nxtNode]});
                    }
                }
            }
            step++;
        }
        return (dis[dst] == 1e9) ? -1 : dis[dst];
    }
};