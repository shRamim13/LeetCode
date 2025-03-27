class Solution
{
public:
    int ans;

    bool isSafe(vector<int> &row_having_queen_col_num, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            int colVal = row_having_queen_col_num[i];
            if (colVal == col || abs(colVal - col) == abs(i - row))
            {
                return false;
            }
        }
        return true;
    }

    void solve(vector<int> &row_having_queen_col_num, int row, int n)
    {
        if (row == n)
        {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row_having_queen_col_num, row, col))
            {
                row_having_queen_col_num[row] = col;
                solve(row_having_queen_col_num, row + 1, n);
                row_having_queen_col_num[row] = -1;
            }
        }
    }

    int totalNQueens(int n)
    {
        ans = 0;
        vector<int> row_having_queen_col_num(n, -1);
        solve(row_having_queen_col_num, 0, n);
        return ans;
    }
};
