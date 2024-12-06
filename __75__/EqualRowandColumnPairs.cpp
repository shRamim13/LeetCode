class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        map<vector<int>, int> rowMap;
        int count = 0;

        for (const auto &row : grid)
        {
            rowMap[row]++;
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> col;
            for (int j = 0; j < n; j++)
            {
                col.push_back(grid[j][i]);
            }
            if (rowMap.count(col))
            {
                count += rowMap[col];
            }
        }

        return count;
    }
};
