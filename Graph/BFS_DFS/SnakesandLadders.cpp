class Solution
{
public:
    int n;
    pair<int, int> _co_ordinate(int idx)
    {
        int row = n - 1 - (idx - 1) / n;
        int col = (idx - 1) % n;
        if (row % 2 == n % 2)
        {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        n = board.size();
        int steps = 0;
        vector<int> vis(n * n + 1, 0);
        queue<int> q;
        vis[1] = 1;
        q.push(1);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int top = q.front();
                q.pop();
                if (top == n * n)
                {
                    return steps;
                }
                for (int k = 1; k <= 6; k++)
                {
                    int idx = top + k;
                    if (idx > n * n)
                    {
                        break;
                    }
                    if (vis[idx] == 1)
                    {
                        continue;
                    }
                    vis[idx] = 1;
                    pair<int, int> row_col = _co_ordinate(idx);
                    int row = row_col.first;
                    int column = row_col.second;
                    if (board[row][column] == -1)
                    {
                        q.push(idx);
                    }
                    else
                    {
                        q.push(board[row][column]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};