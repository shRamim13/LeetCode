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
    int DFS_height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lft = DFS_height(root->left);
        int rgt = DFS_height(root->right);
        if (lft == -1 || rgt == -1)
        {
            return -1;
        }
        if (abs(lft - rgt) > 1)
        {
            return -1;
        }
        return max(lft, rgt) + 1;
    }

    bool isBalanced(TreeNode *root) { return DFS_height(root) != -1; }
};