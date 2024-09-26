
class Solution
{
public:
    int left_Side__height(TreeNode *root)
    {
        TreeNode *cur = root;
        int cnt = 0;
        while (cur != nullptr)
        {
            cnt++;
            cur = cur->left;
        }
        return cnt;
    }
    int right_Side__height(TreeNode *root)
    {
        TreeNode *cur = root;
        int cnt = 0;
        while (cur != nullptr)
        {
            cnt++;
            cur = cur->right;
        }
        return cnt;
    }
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lt_hgt = left_Side__height(root);
        int rt_hgt = right_Side__height(root);
        if (lt_hgt == rt_hgt)
        {
            return (1 << lt_hgt) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// class Solution
// {
// public:
//     int countNodes(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         int cnt1 = 0;
//         int cnt2 = 0;
//         TreeNode *lt = root;
//         TreeNode *rt = root;
//         while (lt != nullptr)
//         {
//             cnt1++;
//             lt = lt->left;
//         }
//         while (rt != nullptr)
//         {
//             cnt2++;
//             rt = rt->right;
//         }
//         if (cnt1 == cnt2)
//         {
//             return (1 << cnt1) - 1;
//         }
//         else
//         {
//             return 1 + countNodes(root->left) + countNodes(root->right);
//         }
//     }
// };
