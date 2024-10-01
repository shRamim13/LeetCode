class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &v, vector<int> &vis)
    {
        if (v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                v.push_back(nums[i]);
                solve(nums, v, vis);
                v.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> v;
        vector<int> vis(nums.size(), 0);
        solve(nums, v, vis);
        return ans;
    }
};

// class Solution
// {
// public:
//     void generatePermutations(vector<int> &nums, int start, vector<vector<int>> &result)
//     {
//         if (start == nums.size() - 1)
//         {
//             result.push_back(nums);
//             return;
//         }

//         for (int i = start; i < nums.size(); ++i)
//         {
//             swap(nums[start], nums[i]);
//             generatePermutations(nums, start + 1, result);
//             swap(nums[start], nums[i]);
//         }
//     }
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> permutations;
//         generatePermutations(nums, 0, permutations);

//         return permutations;
//     }
// };