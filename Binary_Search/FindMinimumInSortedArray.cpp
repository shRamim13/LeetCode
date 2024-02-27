class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int mini = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[l] <= nums[r])
            {
                mini = min(mini, nums[l]);
                break;
            }
            if (nums[l] <= nums[mid])
            {
                mini = min(nums[l], mini);
                l = mid + 1;
            }
            else
            {
                mini = min(nums[mid], mini);
                r = mid - 1;
            }
        }
        return mini;
    }
};
