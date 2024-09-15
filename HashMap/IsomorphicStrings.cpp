class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int x = 0; x < s.size(); x++)
        {
            mp1[s[x]] = x;
        }
        for (int x = 0; x < t.size(); x++)
        {
            mp2[t[x]] = x;
        }
        int v1 = 0, v2 = 0;
        for (int x = 0; x < t.size(); x++)
        {
            if (v1 != v2)
            {
                return false;
            }
            v1 += mp1[s[x]];
            v2 += mp2[t[x]];
        }
        return true;
    }
};