class Solution
{
public:
    int Kadane_Max(vector<int> &nums)
    {
        int maxi_so_far = nums[0];
        int maxi_cur = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxi_cur = max(nums[i], maxi_cur + nums[i]);
            maxi_so_far = max(maxi_so_far, maxi_cur);
        }
        return maxi_so_far;
    }

    int Kadane_Min(vector<int> &nums)
    {
        int mini_so_far = nums[0];
        int mini_cur = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            mini_cur = min(nums[i], mini_cur + nums[i]);
            mini_so_far = min(mini_so_far, mini_cur);
        }
        return mini_so_far;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int minSum = Kadane_Min(nums);
        int maxSum = Kadane_Max(nums);

        // If all numbers are negative, return maxSum (single largest element)
        if (maxSum < 0)
        {
            return maxSum;
        }

        int circularSum = totalSum - minSum;
        return max(maxSum, circularSum);
    }
};
