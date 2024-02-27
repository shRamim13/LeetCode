class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lower == nums.size() || nums[lower] != target)
        {
            return {-1, -1};
        }

        return {lower, upper - 1};
    }
};
