class Solution
{
public:
    int Kadane_Max(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }

    int Kadane_Min(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mini = min(mini, sum);
            if (sum > 0)
            {
                sum = 0;
            }
        }
        return mini;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int minSum = Kadane_Min(nums);
        int maxSum = Kadane_Max(nums);

        // If all numbers are negative, return maxSum (single largest
        // element)
        if (maxSum < 0)
        {
            return maxSum;
        }

        int circularSum = totalSum - minSum;
        return max(maxSum, circularSum);
    }
};
