class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mp(256, -1);
        int maxlen = 0;
        int n = s.size();
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (mp[s[j]] != -1)
            {
                if (mp[s[j]] >= i)
                {
                    i = mp[s[j]] + 1;
                }
            }
            maxlen = max(maxlen, j - i + 1);
            mp[s[j]] = j;
        }

        return maxlen;
    }
};
