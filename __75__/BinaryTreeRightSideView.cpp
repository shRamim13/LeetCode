class Solution {
public:
    void solve(TreeNode* root, int lvl, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        if (v.size() == lvl) {
            v.push_back(root->val);
        }
        solve(root->right, lvl + 1, v);
        solve(root->left, lvl + 1, v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root, 0, v);
        return v;
    }
};