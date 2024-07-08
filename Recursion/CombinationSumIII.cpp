class Solution
{
public:
    void solve(int indx, int sum, int k, int n, vector<int> &v,
               vector<vector<int>> &ans)
    {
        if (sum == n && v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        if (sum > n || indx > 9)
        {
            return;
        }
        for (int i = indx; i <= 9; i++)
        {
            v.push_back(i);
            solve(i + 1, sum + i, k, n, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1, 0, k, n, v, ans);
        return ans;
    }
};