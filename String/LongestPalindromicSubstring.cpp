;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = s.size() - 1; j > i; j--)
            {
                int l = i;
                int r = j;
                while (l <= r && s[l] == s[r])
                {
                    l++;
                    r--;
                }
                if (l > r)
                {
                    int len = j - i + 1;
                    if (len > ans.size())
                    {
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        if (ans == "" && s != "")
        {
            ans = s[0];
        }
        return ans;
    }
};
