class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    pq.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty())
        {
            int row = pq.front().first.first;
            int column = pq.front().first.second;
            int dis = pq.front().second;
            pq.pop();
            distance[row][column] = dis;
            for (auto &x : directions)
            {
                int xx = row + x.first;
                int yy = column + x.second;
                if (xx >= 0 && xx < n && yy >= 0 && yy < m &&
                    vis[xx][yy] == 0)
                {
                    vis[xx][yy] = 1;
                    pq.push({{xx, yy}, dis + 1});
                }
            }
        }
        return distance;
    }
};