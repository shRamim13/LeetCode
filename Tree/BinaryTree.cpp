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
            if (!q.empty())
            {
                q.push(NULL);
            }
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
                q.push(temp->right);
            }
        }
    }
}

void InOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    root = builTree(root);
    cout << "LevelOrder Travarsal \n";
    levelOrderTravarsal(root);

    cout << "InOrder Travarsal ";
    InOrderTraversal(root);
    cout << "\n";
    cout << "PreOrder Travarsal ";
    PreOrderTraversal(root);
    cout << "\n";
    cout << "PostOrder Travarsal ";
    PostOrderTraversal(root);
}
/*
1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
*/