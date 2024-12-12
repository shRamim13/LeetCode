class Solution
{
public:
    int path = 0;
    void solve(TreeNode *root, long long targetSum)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val == targetSum)
        {
            path++;
        }
        solve(root->left, targetSum - root->val);
        solve(root->right, targetSum - root->val);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return path;
        }
        solve(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return path;
    }
};