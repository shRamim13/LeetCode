class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxi = 0;
        int i = 0, j = 0;
        int k = 1;
        int n = nums.size();
        while (j < n)
        {
            if (nums[j] == 0)
            {
                k--;
            }
            while (k < 0)
            {
                if (nums[i] == 0)
                {
                    k++;
                }
                i++;
            }
            maxi = max(maxi, j - i);
            j++;
        }
        return maxi;
    }
};