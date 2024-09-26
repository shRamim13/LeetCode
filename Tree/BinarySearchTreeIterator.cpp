class BSTIterator
{
public:
    stack<TreeNode *> st;
    void loadLeft(TreeNode *root)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode *root) { loadLeft(root); }

    int next()
    {
        TreeNode *cur = st.top();
        st.pop();
        if (cur->right != nullptr)
        {
            loadLeft(cur->right);
        }
        return cur->val;
    }

    bool hasNext() { return !st.empty(); }
};
