class Solution
{
public:
    int helper(vector<int> &s, int k)
    {
        int l = 0, r = 0, n = s.size();
        unordered_map<int, int> mp;
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
            if (mp.size() <= k)
            {
                maxLen += (r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
    int subarraysWithKDistinct(vector<int> &s, int k)
    {
        return helper(s, k) - helper(s, k - 1);
    }
};