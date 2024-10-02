class Solution
{
public:
    TreeNode *solve(vector<int> &nums, int lt, int rt)
    {
        if (lt > rt)
        {
            return nullptr;
        }
        int mid = lt + (rt - lt) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = solve(nums, lt, mid - 1);
        cur->right = solve(nums, mid + 1, rt);
        return cur;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};