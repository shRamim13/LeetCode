class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // Base case: if the node is null, return null
        if (root == nullptr)
        {
            return root;
        }

        // Recursively invert the left and right subtrees
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        // Swap the left and right children
        root->left = right;
        root->right = left;

        return root;
    }
};

// using level order Traversal

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            swap(tmp->left, tmp->right);
            if (tmp->left != nullptr)
            {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                q.push(tmp->right);
            }
        }
        return root;
    }
};