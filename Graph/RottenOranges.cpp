class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return -1;
        }
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> pq;
        int total = 0, cnt = 0, time = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    total++;
                }
                if (grid[i][j] == 2)
                {
                    pq.push({i, j});
                }
            }
        }
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty())
        {
            int k = pq.size();
            cnt += k;
            while (k--)
            {
                int row = pq.front().first;
                int column = pq.front().second;
                pq.pop();
                for (auto &x : directions)
                {
                    int xx = row + x.first;
                    int yy = column + x.second;
                    if (xx < 0 || yy < 0 || xx >= m || yy >= n ||
                        grid[xx][yy] != 1)
                    {
                        continue;
                    }
                    grid[xx][yy] = 2;
                    pq.push({xx, yy});
                }
            }
            if (!pq.empty())
            {
                time++;
            }
        }
        return (cnt == total) ? time : -1;
    }
};