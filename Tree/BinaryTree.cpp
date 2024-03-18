#include <iostream>
#include <queue>
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
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
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

node *buildFromLevelOrder()
{
    queue<node *> q;
    cout << "Enter data for the root \n";
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->data << endl;
        int RightData;
        cin >> RightData;
        if (RightData != -1)
        {
            temp->right = new node(RightData);
            q.push(temp->right);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    // root = builTree(root);

    cout << " Build From Level Order " << endl;
    root = buildFromLevelOrder();

    if (root != NULL)
    {
        cout << "Level Order Traversal: \n";
        levelOrderTravarsal(root);
        cout << endl;

        // cout << "InOrder Traversal: ";
        // InOrderTraversal(root);
        // cout << endl;

        // cout << "PreOrder Traversal: ";
        // PreOrderTraversal(root);
        // cout << endl;

        // cout << "PostOrder Traversal: ";
        // PostOrderTraversal(root);
        // cout << endl;
    }
    else
    {
        cout << "Empty tree!" << endl;
    }

    return 0;
}
