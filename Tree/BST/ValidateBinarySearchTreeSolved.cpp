class Solution
{
public:
    bool _isValidBST(TreeNode *root, long long x, long long y)
    {
        if (root == nullptr)
            return true;
        if (root->val <= x || root->val >= y)
            return false;
        return _isValidBST(root->left, x, root->val) &&
               _isValidBST(root->right, root->val, y);
    }

    bool isValidBST(TreeNode *root)
    {
        return _isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};