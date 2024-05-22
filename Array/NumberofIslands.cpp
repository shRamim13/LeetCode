class Solution
{
private:
    void dfs(int row, int column, vector<vector<int>> &vis,
             vector<vector<char>> &grid)
    {
        int row_sz = grid.size();
        int column_sz = grid[0].size();
        vis[row][column] = 1;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &x : directions)
        {
            int rw = row + x.first;
            int clmn = column + x.second;
            if ((rw >= 0 && rw < row_sz) && (clmn >= 0 && clmn < column_sz) &&
                (vis[rw][clmn] == 0) && (grid[rw][clmn] == '1'))
            {
                dfs(rw, clmn, vis, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int column = grid[0].size();
        if (row == 0)
        {
            return 0;
        }

        vector<vector<int>> vis(row, vector<int>(column, 0));
        int cnt = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};
