class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || p == root || q == root)
        {
            return root;
        }
        TreeNode *lft_tree = lowestCommonAncestor(root->left, p, q);
        TreeNode *rgt_tree = lowestCommonAncestor(root->right, p, q);
        if (lft_tree != nullptr && rgt_tree != nullptr)
        {
            return root;
        }
        return (lft_tree == nullptr) ? rgt_tree : lft_tree;
    }
};