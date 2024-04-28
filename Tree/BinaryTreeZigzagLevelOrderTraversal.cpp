
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int len = q.size();
            vector<int> v(len);
            for (int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                q.pop();
                int indx = (flag) ? i : len - 1 - i;
                v[indx] = temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};