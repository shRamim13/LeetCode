class Solution
{
public:
    void solve(int indx, vector<int> &v, vector<int> &nums,
               vector<vector<int>> &ans)
    {
        if (indx == nums.size())
        {
            ans.push_back(v);
            return;
        }

        v.push_back(nums[indx]);
        solve(indx + 1, v, nums, ans);

        v.pop_back();
        solve(indx + 1, v, nums, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, v, nums, ans);
        return ans;
    }
};
