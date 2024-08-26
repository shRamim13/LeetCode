//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

public:
    const int MOD = 1e9 + 7;
    vector<int> dp = vector<int>(10005, -1); // Initialize dp vector with -1
    // Top-down approach (with memoization)
    long long int topDown(int n)
    {
        if (n == 0)
        {
            return dp[0] = 0;
        }
        if (n == 1)
        {
            return dp[1] = 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = (topDown(n - 1) + topDown(n - 2)) % MOD;
    }

    // Bottom-up approach (iterative)
    long long int bottomUp(int n)
    {
        // if (n == 0) return 0;
        // if (n == 1) return 1;

        // Initialize base cases
        long long int prev2 = 0;
        long long int prev1 = 1;

        // Calculate Fibonacci iteratively with modulo
        for (int i = 2; i <= n; ++i)
        {
            long long int curr = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans)
            cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}