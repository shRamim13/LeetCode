class Solution
{
public:
    void solve(int num, int k, int n, vector<int> &v,
               vector<vector<int>> &ans)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = num; i <= n; i++)
        {
            v.push_back(i);
            solve(i + 1, k, n, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1, k, n, v, ans);
        return ans;
    }
};