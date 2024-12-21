class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        vector<int> v;
        stack<Node *> st;
        Node *cur = root;
        while (!st.empty() || cur != nullptr)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            Node *tmp = st.top();
            st.pop();
            v.push_back(tmp->data);
            cur = tmp->right;
        }
        return v;
    }
};