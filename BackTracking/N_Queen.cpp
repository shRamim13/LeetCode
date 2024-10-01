class Solution
{
public:
    vector<vector<string>> ans;

    bool isValid(int row, int col, int n, vector<string> &v)
    {
        // Check column
        for (int i = row; i >= 0; i--)
        {
            if (v[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (v[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (v[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void solve(int row, int n, vector<string> &v)
    {
        if (row == n)
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isValid(row, i, n, v))
            {
                v[row][i] = 'Q';
                solve(row + 1, n, v);
                v[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> v(n, string(n, '.'));
        solve(0, n, v);
        return ans;
    }
};
