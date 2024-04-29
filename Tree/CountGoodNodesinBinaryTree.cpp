class Solution
{
public:
    int cntGdNode(TreeNode *root, int max_val)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int cnt = 0;
        if (root->val >= max_val)
        {
            cnt++;
            max_val = root->val;
        }

        cnt += cntGdNode(root->left, max_val);
        cnt += cntGdNode(root->right, max_val);
        return cnt;
    }

    int goodNodes(TreeNode *root) { return cntGdNode(root, INT_MIN); }
};
