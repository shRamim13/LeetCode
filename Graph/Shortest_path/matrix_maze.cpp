class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
        {
            return -1;
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {source.first, source.second}});
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == destination.first && y == destination.second)
            {
                return wt;
            }
            for (auto d : dir)
            {
                int xx = x + d.first;
                int yy = y + d.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < grid[0].size() && grid[xx][yy] == 1)
                {
                    pq.push({wt + 1, {xx, yy}});
                    grid[xx][yy] = 0; 
                }
            }
        }
        return -1;
    }
};