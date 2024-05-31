vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<vector<int>> v(N);
    for (auto x : edges)
    {
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
    }

    vector<int> dis(N, 1e9);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto x : v[t])
        {
            if (dis[t] + 1 < dis[x])
            {
                dis[x] = dis[t] + 1;
                q.push(x);
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