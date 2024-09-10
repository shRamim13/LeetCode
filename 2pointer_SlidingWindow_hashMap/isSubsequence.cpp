class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int cnt = 0;
        int i = 0;
        int j = 0;
        int n = t.size();
        while (i < n)
        {
            if (s[j] == t[i])
            {
                i++;
                j++;
                cnt++;
            }

            else
            {
                i++;
            }
        }
        return (cnt == s.size()) ? true : false;
    }
};