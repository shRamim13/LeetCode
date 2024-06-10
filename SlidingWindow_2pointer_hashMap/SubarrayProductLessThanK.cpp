class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int cnt = 0;
        int mul = 1;
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n)
        {
            mul *= nums[j];
            if (i < n && mul >= k)
            {
                mul /= nums[i];
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
};