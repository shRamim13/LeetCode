class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        TreeNode *lt = root;
        TreeNode *rt = root;
        while (lt != nullptr)
        {
            cnt1++;
            lt = lt->left;
        }
        while (rt != nullptr)
        {
            cnt2++;
            rt = rt->right;
        }
        if (cnt1 == cnt2)
        {
            return (1 << cnt1) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
