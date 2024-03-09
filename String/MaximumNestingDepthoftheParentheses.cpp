class Solution
{
public:
    int maxDepth(string s)
    {
        int maxi = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                maxi = max(maxi, ++cnt);
            }
            else if (s[i] == ')')
            {
                cnt--;
            }
        }
        return maxi;
    }
};