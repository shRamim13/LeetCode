class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode *ls = lowestCommonAncestor(root->left, p, q);
        TreeNode *rs = lowestCommonAncestor(root->right, p, q);
        if (ls && rs)
        {
            return root;
        }
        return ls ? ls : rs;
    }
};