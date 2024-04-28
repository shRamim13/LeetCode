class Solution
{
public:
    bool isIdentical(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr || root2 == nullptr)
        {
            return root1 == root2;
        }
        return (root1->val == root2->val) &&
               isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }
        return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
