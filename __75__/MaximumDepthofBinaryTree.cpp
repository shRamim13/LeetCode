class Solution
{
public:
    int calculateDepth(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode *root)
    {
        return calculateDepth(root);
    }
};



/*
class Solution {
public:
    int _maxDepth = 0;
    void solve(TreeNode* root, int depth) {
        if (root == nullptr) {
            _maxDepth = max(depth, _maxDepth);
            return;
        }
        solve(root->left, depth + 1);
        solve(root->right, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        solve(root, 0);
        return _maxDepth;
    }
};

*/