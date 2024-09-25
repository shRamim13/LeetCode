
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return root;
        }

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *current = q.front();
                q.pop();
                if (i < size - 1)
                {
                    current->next = q.front();
                }
                if (current->left != nullptr)
                {
                    q.push(current->left);
                }
                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }
        }
        return root;
    }
};