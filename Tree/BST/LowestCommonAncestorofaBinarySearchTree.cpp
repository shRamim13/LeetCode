class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode *lft = lowestCommonAncestor(root->left, p, q);
        TreeNode *rft = lowestCommonAncestor(root->right, p, q);
        if (lft == nullptr)
        {
            return rft;
        }
        if (rft == nullptr)
        {
            return lft;
        }
        return root;
    }
};