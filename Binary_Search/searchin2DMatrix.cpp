class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();

        int l = 0;
        int r = rows * cols - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int midVal = matrix[mid / cols][mid % cols];

            if (midVal == target)
                return true;
            else if (midVal < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};
