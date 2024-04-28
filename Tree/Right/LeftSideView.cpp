class Solution
{
public:
    void helper(TreeNode *root, vector<int> &v, int lvl)
    {
        if (root == nullptr)
        {
            return;
        }

        if (v.size() == lvl)
        {
            v.push_back(root->val);
        }
        helper(root->right, v, lvl + 1);
        helper(root->left, v, lvl + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        int lvl = 0;
        helper(root, v, lvl);
        return v;
    }
};