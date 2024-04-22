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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *t1 = root->right;
                delete root;
                return t1;
            }
            if (root->right == nullptr)
            {
                TreeNode *t2 = root->left;
                delete root;
                return t2;
            }
            TreeNode *temp = root->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};