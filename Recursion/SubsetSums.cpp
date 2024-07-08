class Solution
{
public:
    void solve(int indx, int sum, int n, vector<int> arr, vector<int> &ans)
    {
        if (indx == n)
        {
            ans.push_back(sum);
            return;
        }
        solve(indx + 1, sum + arr[indx], n, arr, ans);
        solve(indx + 1, sum, n, arr, ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        int sum = 0;
        solve(0, sum, n, arr, ans);
        return ans;
    }
};