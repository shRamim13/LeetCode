class Solution
{
public:
    int solve(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 10 * sum + root->val;
        }
        return solve(root->left, 10 * sum + root->val) +
               solve(root->right, 10 * sum + root->val);
    }
    int sumNumbers(TreeNode *root) { return solve(root, 0); }
};