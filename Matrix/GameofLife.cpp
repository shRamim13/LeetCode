class Solution
{
public:
    void gameOfLife(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> dir = {
            {1, 0},  // Move right
            {-1, 0}, // Move left
            {0, 1},  // Move down
            {0, -1}, // Move up
            {1, 1},  // Move down-right
            {1, -1}, // Move down-left
            {-1, 1}, // Move up-right
            {-1, -1} // Move up-left
        };

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int liveCell = 0;
                for (auto &[x, y] : dir)
                {
                    int xx = i + x;
                    int yy = j + y;
                    if (xx >= 0 && xx < rows && yy >= 0 && yy < cols &&
                        abs(matrix[xx][yy]) == 1)
                    {
                        liveCell++;
                    }
                }
                if (matrix[i][j] == 1 && (liveCell < 2 || liveCell > 3))
                {
                    matrix[i][j] = -1;
                }
                else if (matrix[i][j] == 0 && liveCell == 3)
                {
                    matrix[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] >= 1)
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
