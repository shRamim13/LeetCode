class Solution
{
public:
    void solve(int indx, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (indx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = indx; i < nums.size(); i++)
        {
            swap(nums[indx], nums[i]);
            solve(indx + 1, nums, ans);
            swap(nums[indx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};

// class Solution {
// public:
//     void solve(vector<int>& nums, vector<int>& current, vector<bool>& used,
//                vector<vector<int>>& ans) {
//         if (current.size() == nums.size()) {
//             ans.push_back(current);
//             return;
//         }

//         for (int i = 0; i < nums.size(); ++i) {
//             if (used[i])
//                 continue;
//             used[i] = true;
//             current.push_back(nums[i]);
//             solve(nums, current, used, ans);
//             current.pop_back();
//             used[i] = false;
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> current;
//         vector<bool> used(nums.size(), false);
//         solve(nums, current, used, ans);
//         return ans;
//     }
// };
