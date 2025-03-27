/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, lt, mid - 1);
        root->right = solve(nums, mid + 1, rt);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int lt = 0;
        int rt = nums.size() - 1;
        return solve(nums, lt, rt);
    }
};