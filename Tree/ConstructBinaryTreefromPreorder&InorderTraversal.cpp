class Solution
{
public:
    TreeNode *helper(vector<int> &preorder, int preStr, int preEnd,
                     vector<int> &inorder, int inStr, int inEnd,
                     map<int, int> &mp)
    {
        if (preStr > preEnd || inStr > inEnd)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preStr]);
        int indx = mp[root->val];
        int leftLen = indx - inStr;
        root->left = helper(preorder, preStr + 1, preStr + leftLen, inorder,
                            inStr, indx - 1, mp);
        root->right = helper(preorder, preStr + leftLen + 1, preEnd, inorder,
                             indx + 1, inEnd, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0,
                      inorder.size() - 1, mp);
    }
};
