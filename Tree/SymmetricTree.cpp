class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return (p == q);
        }
        return (p->val == q->val) && isSameTree(p->left, q->right) &&
               isSameTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (isSameTree(root->left, root->right) == true)
        {
            return true;
        };
        return false;
    }
};