class Solution
{
public:
    int rows, cols;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Down, Up, Right, Left

    bool dfs(vector<vector<char>> &board, string &word, int i, int row,
             int col)
    {
        if (i == word.size())
            return true;

        if (row < 0 || row >= rows || col < 0 || col >= cols ||
            board[row][col] != word[i])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';

        for (auto [dr, dc] : directions)
        {
            int newRow = row + dr, newCol = col + dc;
            if (dfs(board, word, i + 1, newRow, newCol))
            {
                return true;
            }
        }

        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (board[row][col] == word[0] &&
                    dfs(board, word, 0, row, col))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
