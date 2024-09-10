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
            t += (nums[r] % 2);
            while (t > k)
            {
                t -= (nums[l] % 2);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        if (k == 0)
            return helper(nums, k);
        return helper(nums, k) - helper(nums, k - 1);
    }
};