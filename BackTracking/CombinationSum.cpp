class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &candidates, vector<int> &v, int target, int indx)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (target < 0)
        {
            return;
        }
        for (int i = indx; i < candidates.size(); i++)
        {
            v.push_back(candidates[i]);
            solve(candidates, v, target - candidates[i], i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        int indx = 0;
        solve(candidates, v, target, indx);
        return ans;
    }
};