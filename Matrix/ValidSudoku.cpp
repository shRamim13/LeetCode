class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> st;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    string row = "row" + to_string(i) + board[i][j];
                    string column = "column" + to_string(j) + board[i][j];
                    string square =
                        "square" + to_string((i / 3) * 3 + j / 3) + board[i][j];
                    if (!st.insert(row).second || !st.insert(column).second ||
                        !st.insert(square).second)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
