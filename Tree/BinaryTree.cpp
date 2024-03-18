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

int main()
{
    node *root = NULL;
    root = builTree(root);
}