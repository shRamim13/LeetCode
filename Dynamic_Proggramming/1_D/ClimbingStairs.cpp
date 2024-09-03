class Solution
{
public:
    int solve(vector<int> &dp, int n)
    {
        if (n == 1 || n == 2)
            return n;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int stp_1 = solve(dp, n - 1);
        int stp_2 = solve(dp, n - 2);
        return dp[n] = stp_1 + stp_2;
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};
