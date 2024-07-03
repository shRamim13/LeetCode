class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = 0; i <= 3; i++)
        {
            minDiff = min(minDiff, nums[n - 4 + i] - nums[i]);
        }
        return minDiff;
    }
};

// 1 2 3 4 5 6 7 8 9

// 4 4 4 4 5 6 7 8 9 --- 5
// 1 2 3 4 5 6 6 6 6 --- 5
// 3 3 3 4 5 6 7 8 8 --- 5
// 2 2 3 4 5 6 7 7 7 --- 5
