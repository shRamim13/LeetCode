class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &isConnected)
    {
        vis[node] = 1;
        for (int i = 0; i < isConnected[node].size(); i++)
        {
            if (isConnected[node][i] == 1 && vis[i] == 0)
            {

                dfs(i, vis, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> vis(isConnected.size(), 0);
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};