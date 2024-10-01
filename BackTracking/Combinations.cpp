class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int start, vector<int> &v)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            v.push_back(i);
            solve(n, k, i + 1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        solve(n, k, 1, v);
        return ans;
    }
};