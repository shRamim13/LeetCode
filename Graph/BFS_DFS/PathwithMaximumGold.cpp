class Solution
{
public:
    int maxCnt = 0;
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(int rw, int cl, int &cnt, vector<vector<int>> &grid)
    {
        if (rw == grid.size() && cl == grid[0].size())
        {
            return;
        }
        int ssd = grid[rw][cl];
        cnt += ssd;
        maxCnt = max(cnt, maxCnt);
        grid[rw][cl] = 0;
        for (auto x : dir)
        {
            int xx = x.first + rw;
            int yy = x.second + cl;
            if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size() &&
                grid[xx][yy] != 0)
            {
                solve(xx, yy, cnt, grid);
            }
        }
        grid[rw][cl] = ssd;
        cnt -= ssd;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    solve(i, j, cnt, grid);
                }
            }
        }
        return maxCnt;
    }
};