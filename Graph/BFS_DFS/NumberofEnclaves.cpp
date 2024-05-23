class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &grid,
             vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto &dir : directions)
        {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 &&
                vis[x][y] == 0)
            {
                dfs(x, y, grid, vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
        {
            if (grid[i][0] == 1 && vis[i][0] == 0)
            {
                dfs(i, 0, grid, vis);
            }
            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0)
            {
                dfs(i, m - 1, grid, vis);
            }
        }
        for (int j = 0; j < m; ++j)
        {
            if (grid[0][j] == 1 && vis[0][j] == 0)
            {
                dfs(0, j, grid, vis);
            }
            if (grid[n - 1][j] == 1 && vis[n - 1][j] == 0)
            {
                dfs(n - 1, j, grid, vis);
            }
        }

        int enclaveCount = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    enclaveCount++;
                }
            }
        }

        return enclaveCount;
    }
};
