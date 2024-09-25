
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (cur->right)
            {
                st.push(cur->right);
            }
            if (cur->left)
            {
                st.push(cur->left);
            }
            if (!st.empty())
            {
                cur->right = st.top();
            }
            cur->left = nullptr;
        }
    }
};
