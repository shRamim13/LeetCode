class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
    }

    int next()
    {
        TreeNode *cur = st.top();
        st.pop();
        int value = cur->val;
        cur = cur->right;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        return value;
    };
    bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */