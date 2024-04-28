#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

node *buildTree()
{
    cout << "Enter the data(or -1 to stop)" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    node *root = new node(data);
    cout << "Enter data for the left child of " << root->data << endl;
    root->left = buildTree();
    cout << "Enter data for the right child of " << root->data << endl;
    root->right = buildTree();

    return root;
}

void deleteTree(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

vector<vector<int>> levelOrderTraversal(node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v;
        for (int i = 0; i < sz; i++)
        {
            node *temp = q.front();
            q.pop();
            v.push_back(temp->data);
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

void InOrderTraversal(node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    InOrderTraversal(root->left, ans);
    ans.push_back(root->data);
    InOrderTraversal(root->right, ans);
}

void PreOrderTraversal(node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    ans.push_back(root->data);
    PreOrderTraversal(root->left, ans);
    PreOrderTraversal(root->right, ans);
}

void PostOrderTraversal(node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    PostOrderTraversal(root->left, ans);
    PostOrderTraversal(root->right, ans);
    ans.push_back(root->data);
}

int height_or_depth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_height = height_or_depth(root->left);
    int right_height = height_or_depth(root->right);
    return 1 + max(left_height, right_height);
}

// balance binary tree
int helper_height_or_depth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_height = height_or_depth(root->left);
    int right_height = height_or_depth(root->right);
    if (abs(left_height - right_height) > 1)
        return -1;
    return 1 + max(left_height, right_height);
}

bool isTreeBalanced(node *root)
{
    if (helper_height_or_depth(root) == -1)
        return false;
    return true;
}

// diameter
int diameterHelper(node *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_height = diameterHelper(root->left, diameter);
    int right_height = diameterHelper(root->right, diameter);
    diameter = max(diameter, left_height + right_height);
    return 1 + max(left_height, right_height);
}

int diameterofTree(node *root)
{
    int d = 0;
    diameterHelper(root, d);
    return d;
}

int main()
{
    node *root = buildTree();

    // vector<vector<int>> ans = levelOrderTraversal(root);

    // for (auto x : ans)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> v;
    // InOrderTraversal(root, v);
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }

    // vector<int> v;
    // PreOrderTraversal(root, v);
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }

    // vector<int> v;
    // PostOrderTraversal(root, v);
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << "Height of the tree -> " << height_or_depth(root);

    // cout << (isTreeBalanced(root) ? "Tree is balanced " : "Tree is not balanced");
    cout << diameterofTree(root);

    deleteTree(root);
    return 0;
}