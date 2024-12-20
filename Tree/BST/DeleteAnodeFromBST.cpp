class Solution
{
public:
    int findMinFromRightSubTree(TreeNode *root, int val)
    {
        int minVal = val;
        while (root)
        {
            minVal = root->val;
            root = root->left;
        }
        return minVal;
    }
    TreeNode *deleteNode(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (val < root->val)
        {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->val)
        {
            root->right = deleteNode(root->right, val);
        }
        else
        {
            if (root->left == nullptr)
            {
                return root->right;
            }
            else if (root->right == nullptr)
            {
                return root->left;
            }
            root->val = findMinFromRightSubTree(root->right, val);
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};