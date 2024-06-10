class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;

        int cnt = 0;
        int mul = 1;
        int n = nums.size();
        int i = 0, j = 0;

        while (j < n)
        {
            mul *= nums[j];
            while (mul >= k)
            {
                mul /= nums[i];
                i++;
            }
            if (mul < k)
                cnt += (j - i + 1);
            j++;
        }

        return cnt;
    }
};
