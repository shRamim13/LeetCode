class Solution
{
public:
    int helper(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size();
        int ans = 0;
        int t = 0;
        while (r < n)
        {
            t += nums[r];
            while (t > k)
            {
                t -= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        if (goal == 0)
            return helper(nums, goal);
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};
