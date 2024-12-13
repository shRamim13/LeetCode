class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        int max_lvl = 1;
        int lvl = 1;
        int maxSum = INT_MIN;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                auto newNode = q.front();
                q.pop();
                sum += newNode->val;
                if (newNode->left) {
                    q.push(newNode->left);
                }
                if (newNode->right) {
                    q.push(newNode->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                max_lvl = lvl;
            }
            lvl++;
        }
        return max_lvl;
    }
};