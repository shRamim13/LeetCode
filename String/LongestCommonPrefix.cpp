class Solution
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        sort(v.begin(), v.end());
        string s = "";
        string s1 = v[0];
        string s2 = v[v.size() - 1];
        for (int i = 0; i < max(s1.size(), s2.size()); i++)
        {
            if (s1[i] == s2[i])
            {
                s += s1[i];
            }
            else
            {
                break;
            }
        }
        return s;
    }
};