vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (auto s : adj[x])
        {
            indegree[s]--;
            if (indegree[s] == 0)
            {
                q.push(s);
            }
        }
    }

    return ans;
}