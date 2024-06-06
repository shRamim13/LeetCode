#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;

        while (!pq.empty())
        {
            auto [elevation, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;
            if (x == n - 1 && y == m - 1)
            {
                return elevation;
            }
            for (auto [dx, dy] : dir)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
                {
                    visited[nx][ny] = true;

                    pq.push({max(elevation, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1;
    }
};
