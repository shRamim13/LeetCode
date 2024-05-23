class Solution
{
public:
    void dfs(int row, int column, vector<vector<char>> &board,
             vector<vector<int>> &vis)
    {
        int m = board.size();
        int n = board[0].size();
        vis[row][column] = 1;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto &x : directions)
        {
            int xx = row + x.first;
            int yy = column + x.second;
            if (xx >= 0 && xx < m && yy >= 0 && yy < n &&
                board[xx][yy] == 'O' && vis[xx][yy] == 0)
            {
                dfs(xx, yy, board, vis);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int column = board[0].size();
        vector<vector<int>> vis(row, (vector<int>(column, 0)));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if ((i == 0 || i == row - 1 || j == 0 || j == column - 1) &&
                    board[i][j] == 'O' && vis[i][j] == 0)
                {
                    dfs(i, j, board, vis);
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};