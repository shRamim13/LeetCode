class Solution
{
public:
    int minDif = INT_MAX;
    TreeNode *previous = nullptr;
    void solve(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        solve(root->left);
        if (previous != nullptr)
        {
            minDif = min(minDif, root->val - previous->val);
        }
        previous = root;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        solve(root);
        return minDif;
    }
};