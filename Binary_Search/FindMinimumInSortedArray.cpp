Find Minimum in Rotated Sorted Array
    Solved class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lt = 0;
        int rt = nums.size() - 1;
        int maxi = INT_MAX;
        while (lt < rt)
        {
            int mid = lt + (rt - lt) / 2;
            if (nums[lt] <= nums[mid] && nums[mid] > nums[rt])
            {
                lt = mid + 1;
            }
            else
            {
                rt = mid;
            }
        }
        return nums[lt];
    }
};