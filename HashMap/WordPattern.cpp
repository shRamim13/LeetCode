class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        unordered_map<string, char> mp;
        unordered_set<char> st;
        stringstream ssd(s);
        string tmp;
        while (getline(ssd, tmp, ' '))
        {
            v.push_back(tmp);
        }
        if (v.size() != pattern.size())
        {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(v[i]) == mp.end() && st.find(pattern[i]) == st.end())
            {
                st.insert(pattern[i]);
                mp[v[i]] = pattern[i];
            }
            else if (mp[v[i]] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};