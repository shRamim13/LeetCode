class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &arr, vector<int> &v, int target, int indx)
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
        for (int i = indx; i < arr.size(); i++)
        {
            if (i != indx && arr[i] == arr[i - 1])
            {
                continue;
            }
            v.push_back(arr[i]);
            solve(arr, v, target - arr[i], i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<int> v;
        int indx = 0;
        solve(arr, v, target, indx);
        return ans;
    }
};