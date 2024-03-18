#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *builTree(node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting the left of " << data << endl;
    root->left = builTree(root->left);
    cout << "Enter data for inserting the right of " << data << endl;
    root->right = builTree(root->right);
    return root;
}

void levelOrderTravarsal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right)
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = builTree(root);

    levelOrderTravarsal(root);
}