class Solution
{
public:
    void solve(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
        {
            return;
        }
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
    bool solve2Sum(vector<int> &v, int k)
    {
        int i = 0;
        int j = v.size() - 1;
        while (i < j)
        {
            if (v[i] + v[j] < k)
            {
                i++;
            }
            else if (v[i] + v[j] > k)
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> v;
        solve(root, v);
        return solve2Sum(v, k);
    }
    
};