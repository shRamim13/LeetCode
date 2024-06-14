// #include <bits/stdc++.h>
// using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int l = 0, r = 0, n = s.size();
        unordered_map<char, int> mp;
        int maxLen = -1;
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
            if (mp.size() == k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string s;
//         cin >> s;
//         int k;
//         cin >> k;
//         Solution ob;
//         cout << ob.longestKSubstr(s, k) << endl;
//     }
// }
