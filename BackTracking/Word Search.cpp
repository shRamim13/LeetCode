class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (dfs(board, word, i, j, 0) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i + 1, j, index + 1) || // Down
                     dfs(board, word, i - 1, j, index + 1) || // Up
                     dfs(board, word, i, j + 1, index + 1) || // Right
                     dfs(board, word, i, j - 1, index + 1);   // Left

        board[i][j] = temp;

        return found;
    }
};
