class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp, mp2;
        for (int i = 0; i < s.length(); ++i)
        {
            if (mp[s[i]] && mp[s[i]] != t[i])
                return false;
            if (mp2[t[i]] && mp2[t[i]] != s[i])
                return false;
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.length();i++)
        {
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }

        return true;
    }
};
*/