//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int l = 0;
        int r = mat.size() - 1;
        while (l < r)
        {
            if (mat[l][r] == 1)
            {
                l++;
            }
            else if (mat[r][l] == 1)
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        if (l > r)
        {
            return -1;
        }
        for (int i = 0; i < mat.size(); i++)
        {
            if (l == i)
            {
                continue;
            }
            if (mat[l][i] == 0 && mat[i][l] == 1)
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        return l;
    }

    //      0 1 2 3 4

    // 0    0 1 1 0 1

    // 1    0 1 1 0 0

    // 2    0 0 0 0 0  <-

    // 3    1 0 1 0 0

    // 4    0 1 1 0 0
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}
