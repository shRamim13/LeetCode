class Solution
{
public:
    bool solve(TreeNode *root, long mini, long maxi)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= mini || root->val >= maxi)
        {
            return false;
        }
        return solve(root->left, mini, root->val) &&
               solve(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode *root)
    {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};

/*
class Solution {
public:
    bool solve(TreeNode* root, long mini, long maxi) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= mini || root->val >= maxi) {
            return false;
        }
        return solve(root->left, mini, root->val) &&
               solve(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};


*/

// class Solution
// {
// public:
//     void solve(TreeNode *root, vector<int> &v)
//     {
//         if (root == nullptr)
//         {
//             return;
//         }
//         solve(root->left, v);
//         v.push_back(root->val);
//         solve(root->right, v);
//     }
//     bool isValidBST(TreeNode *root)
//     {
//         vector<int> v;
//         solve(root, v);
//         for (int i = 0; i < v.size() - 1; i++)
//         {
//             if (v[i + 1] <= v[i])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };