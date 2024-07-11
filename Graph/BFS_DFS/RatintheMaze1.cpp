class Solution
{
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(int row, int col, string path, vector<string> &ans, vector<vector<int>> &m, int n)
    {
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }

        m[row][col] = 0;

        for (auto &d : dir)
        {
            int newRow = row + d.first;
            int newCol = col + d.second;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && m[newRow][newCol] == 1)
            {
                char direction = (d == pair<int, int>{1, 0}) ? 'D' : (d == pair<int, int>{-1, 0}) ? 'U'
                                                                 : (d == pair<int, int>{0, 1})    ? 'R'
                                                                                                  : 'L';
                solve(newRow, newCol, path + direction, ans, m, n);
            }
        }

        m[row][col] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 1)
        {
            solve(0, 0, "", ans, m, n);
        }
        return ans;
    }
};
