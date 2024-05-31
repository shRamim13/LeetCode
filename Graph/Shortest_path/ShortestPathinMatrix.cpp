///  using bfs
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1)
            {
                return grid[x][y];
            }

            for (auto d : dir)
            {
                int xx = x + d.first;
                int yy = y + d.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 0)
                {
                    q.push({xx, yy});
                    grid[xx][yy] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
};

///// using dijkstra

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        pq.push({1, {0, 0}});
        grid[0][0] = 1;
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == n - 1 && y == n - 1)
            {
                return wt;
            }
            for (auto d : dir)
            {
                int xx = x + d.first;
                int yy = y + d.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n &&
                    grid[xx][yy] == 0)
                {
                    pq.push({wt + 1, {xx, yy}});
                    grid[xx][yy] = 1;
                }
            }
        }
        return -1;
    }
};
