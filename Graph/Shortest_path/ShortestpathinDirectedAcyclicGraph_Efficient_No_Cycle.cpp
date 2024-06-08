class Solution
{
public:
    void topo(int node, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &v)
    {
        vis[node] = 1;
        for (auto x : v[node])
        {
            int ssd = x.first;
            if (vis[ssd] == 0)
            {
                topo(ssd, vis, st, v);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> v(N);
        for (auto x : edges)
        {
            v[x[0]].push_back({x[1], x[2]});
        }

        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                topo(i, vis, st, v);
            }
        }

        vector<int> dis(N, 1e9);
        dis[0] = 0;

        while (!st.empty())
        {
            int t = st.top();
            st.pop();

            for (auto x : v[t])
            {
                if (dis[t] + x.second < dis[x.first])
                {
                    dis[x.first] = dis[t] + x.second;
                }
            }
        }

        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (dis[i] != 1e9)
            {
                ans[i] = dis[i];
            }
        }
 
        return ans;
    }
};