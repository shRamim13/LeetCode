class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int digit, int k, int n, vector<int> &v)
    {
        if (n == 0 && k == 0)
        {
            ans.push_back(v);
            return;
        }
        if (n < 0 || k < 0)
        {
            return;
        }
        for (int i = digit; i <= 9; i++)
        {
            v.push_back(i);
            solve(i + 1, k - 1, n - i, v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> v;
        solve(1, k, n, v);
        return ans;
    }
};
