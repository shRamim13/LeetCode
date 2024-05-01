class Solution
{
public:
    TreeNode *helper(vector<int> &inorder, int inSt, int inEnd,
                     vector<int> &postorder, int postSt, int postEnd,
                     map<int, int> &mp)
    {
        if (inSt > inEnd || postSt > postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int indx = mp[root->val];
        int dif = indx - inSt;
        root->left = helper(inorder, inSt, indx - 1, postorder, postSt,
                            postSt + dif - 1, mp);
        root->right = helper(inorder, indx + 1, inEnd, postorder, postSt + dif,
                             postEnd - 1, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return helper(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};
