class Solution
{
public:
    void solve(TreeNode *root, int flag, int cnt, int &maxi)
    {
        if (root == nullptr)
            return;
        maxi = max(maxi, cnt);
        if (flag == -1)
        {
            solve(root->right, 1, cnt + 1, maxi);
            solve(root->left, -1, 1, maxi);
        }
        else if (flag == 1)
        {
            solve(root->left, -1, cnt + 1, maxi);
            solve(root->right, 1, 1, maxi);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        int maxi = 0;
        solve(root, -1, 0, maxi);
        solve(root, 1, 0, maxi);
        return maxi;
    }
};

// class Solution {
// public:
//     int maxi = INT_MIN;
//     void solve(TreeNode* root, int flag, int cnt) {
//         if (root == nullptr) {
//             return;
//         }
//         maxi = max(maxi, cnt);
//         cnt++;
//         if (flag == 0) {
//             solve(root->left, -1, cnt);
//             solve(root->right, 1, cnt);
//         } else if (flag == -1) {
//             solve(root->right, 1, cnt);
//         } else {
//             solve(root->left, -1, cnt);
//         }
//     }
//     int longestZigZag(TreeNode* root) {
//         if (root) {
//             solve(root, 0, 0);
//             longestZigZag(root->left);
//             longestZigZag(root->right);
//         }
//         return maxi;
//     }
// };