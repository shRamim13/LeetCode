class Solution
{
public:
    int bfsHeight(TreeNode *root, int &s)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt = bfsHeight(root->left, s);
        if (lt == -1)
        {
            return -1;
        }
        int rt = bfsHeight(root->right, s);
        if (rt == -1)
        {
            return -1;
        }
        if (abs(lt - rt) > 1)
        {
            return -1;
        }
        return 1 + max(lt, rt);
    }
    bool isBalanced(TreeNode *root)
    {
        int s = 0;
        s = bfsHeight(root, s);
        if (s == -1)
            return false;
        return true;
    }
};