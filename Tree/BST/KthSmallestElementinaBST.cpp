class Solution
{
public:
    int val = -1;
    void solve(TreeNode *root, int &k)
    {
        if (root == nullptr)
        {
            return;
        }
        solve(root->left, k);
        k--;
        if (k == 0)
        {
            val = root->val;
            return;
        }
        solve(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        solve(root, k);
        return val;
    }
};
// class Solution
// {
// public:
//     // void inorder(TreeNode* root, vector<int>& v) {
//     //     if (root == NULL) {
//     //         return;
//     //     }
//     //     inorder(root->left, v);
//     //     v.push_back(root->val);
//     //     inorder(root->right, v);
//     // }

//     // int kthSmallest(TreeNode* root, int k) {
//     //     vector<int> v;
//     //     inorder(root, v);
//     //     return v[k-1];
//     // }