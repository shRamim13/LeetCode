class Solution
{
public:
    void dfs(int i, int j, int &newColor, int &initColor, vector<vector<int>> &image, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        image[i][j] = newColor;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto &direction : directions)
        {
            int xx = i + direction.first;
            int yy = j + direction.second;
            if (xx >= 0 && xx < image.size() && yy >= 0 && yy < image[0].size() &&
                image[xx][yy] == initColor && vis[xx][yy] == 0)
            {
                dfs(xx, yy, newColor, initColor, image, vis);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        int initColor = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));

        if (initColor != newColor)
        {
            dfs(sr, sc, newColor, initColor, image, vis);
        }

        return image;
    }
};
