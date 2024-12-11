class Solution
{
public:
    void solve(TreeNode *root, int targetSum, vector<int> &v,
               vector<vector<int>> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        v.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val == targetSum)
            {
                ans.push_back(v);
            }
            v.pop_back();
            return;
        }
        solve(root->left, targetSum - root->val, v, ans);
        solve(root->right, targetSum - root->val, v, ans);
        v.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        vector<int> v;
        solve(root, targetSum, v, ans);
        return ans;
    }
};