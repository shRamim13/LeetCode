class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        // Compute the prefix sums for each row
        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int cnt = 0;

        // Iterate over all pairs of columns
        for (int startCol = 0; startCol < col; startCol++)
        {
            for (int endCol = startCol; endCol < col; endCol++)
            {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cumulativeSum = 0;

                // Iterate over all rows to calculate submatrix sums
                for (int rowNum = 0; rowNum < row; rowNum++)
                {

                    cumulativeSum +=
                        matrix[rowNum][endCol] -
                        (startCol > 0 ? matrix[rowNum][startCol - 1] : 0);

                    // Check if the cumulative sum minus target exists in the
                    // map
                    if (mp.count(cumulativeSum - target))
                    {
                        cnt += mp[cumulativeSum - target];
                    }

                    // Update the hashmap with the current cumulative sum
                    mp[cumulativeSum]++;
                }
            }
        }

        return cnt;
    }
};
