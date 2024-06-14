#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int l = 0, r = 0, n = s.size();
        unordered_map<char, int> mp;
        int maxLen = 0; // Initialize maxLen to 0 to handle cases where no valid substring is found

        while (r < n)
        {
            mp[s[r]]++;
            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};

// Driver code for testing
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
    return 0;
}
