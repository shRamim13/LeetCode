class Solution
{
public:
    void solve(TreeNode *root, int &cnt, int prev_max)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val >= prev_max)
        {
            cnt++;
            prev_max = root->val;
        }

        solve(root->left, cnt, prev_max);
        solve(root->right, cnt, prev_max);
    }

    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        solve(root, cnt, root->val);
        return cnt;
    }
};
