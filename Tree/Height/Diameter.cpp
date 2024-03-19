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
    int dfs(TreeNode *root, int &maxDiameter)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftDepth = dfs(root->left, maxDiameter);
        int rightDepth = dfs(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxDiameter = 0;
        dfs(root, maxDiameter);
        return maxDiameter;
    }
};
