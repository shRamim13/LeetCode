class Solution
{
public:
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void solve(int rw, int cl, int indx, bool &flag,
               vector<vector<char>> &board, const string &word)
    {
        // if (flag)
        //     return;
        if (indx == word.size())
        {
            flag = true;
            return;
        }

        char temp = board[rw][cl];
        board[rw][cl] = '#';

        for (auto &x : dir)
        {
            int xx = rw + x.first;
            int yy = cl + x.second;

            if (xx >= 0 && xx < board.size() && yy >= 0 &&
                yy < board[0].size() && board[xx][yy] == word[indx])
            {
                solve(xx, yy, indx + 1, flag, board, word);
                if (flag)
                {
                    return;
                }
            }
        }

        board[rw][cl] = temp;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty() || word.empty())
            return false;

        int m = board.size();
        int n = board[0].size();
        bool flag = false;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    solve(i, j, 1, flag, board, word);
                    if (flag)
                        return true;
                }
            }
        }

        return false;
    }
};
