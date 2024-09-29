
class Solution
{
public:
    int cnt;
    int result;
    void solve(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        solve(root->left);
        cnt--;
        if (cnt == 0)
        {
            result = root->val;
            return;
        }

        solve(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        cnt = k;
        solve(root);
        return result;
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