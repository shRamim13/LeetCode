class Solution
{
public:
    int solve_left(vector<int> &nums, int n, int target)
    {
        int leftMost = -1;
        int lt = 0;
        int rt = n;
        while (lt <= rt)
        {
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] == target)
            {
                leftMost = mid;
                rt = mid - 1;
            }
            else if (nums[mid] < target)
            {
                lt = mid + 1;
            }
            else
            {
                rt = mid - 1;
            }
        }
        return leftMost;
    }

    int solve_right(vector<int> &nums, int n, int target)
    {
        int rightMost = -1;
        int lt = 0;
        int rt = n;
        while (lt <= rt)
        {
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] == target)
            {
                rightMost = mid;
                lt = mid + 1;
            }
            else if (nums[mid] < target)
            {
                lt = mid + 1;
            }
            else
            {
                rt = mid - 1;
            }
        }
        return rightMost;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size() - 1;
        int leftMost = solve_left(nums, n, target);
        int rightMost = solve_right(nums, n, target);
        return {leftMost, rightMost};
    }
};

// class Solution
// {
// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {

//         int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

//         int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

//         if (lower == nums.size() || nums[lower] != target)
//         {
//             return {-1, -1};
//         }

//         return {lower, upper - 1};
//     }
// };
