
class Solution
{
public:
    int dfs(TreeNode *root, int &sum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lft = max(0, dfs(root->left, sum));
        int rgt = max(0, dfs(root->right, sum));
        sum = max(sum, lft + rgt + root->val);
        return root->val + max(rgt, lft);
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
};

/*class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        int left_root_right = root->val + left + right;
        int only_root = root->val;
        int left_root_or_root_right = root->val + max(left, right);

        maxSum =
            max({maxSum, left_root_right, only_root, left_root_or_root_right});

        return max(only_root, left_root_or_root_right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
*/