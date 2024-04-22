/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    // void inorder(TreeNode* root, vector<int>& v) {
    //     if (root == NULL) {
    //         return;
    //     }
    //     inorder(root->left, v);
    //     v.push_back(root->val);
    //     inorder(root->right, v);
    // }

    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> v;
    //     inorder(root, v);
    //     return v[k-1];
    // }

    void cntBST(TreeNode *root, int &k, int &ans)
    {
        if (root == nullptr || k == 0)
        {
            return;
        }
        cntBST(root->left, k, ans);
        if (--k == 0)
        {
            ans = root->val;
            return;
        }
        cntBST(root->right, k, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int ans = 0;
        cntBST(root, k, ans);
        return ans;
    }
};