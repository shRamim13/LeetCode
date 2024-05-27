class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto y : graph[i])
            {
                reverseGraph[y].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            int ssd = q.front();
            q.pop();
            ans.push_back(ssd);
            for (auto x : reverseGraph[ssd])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};