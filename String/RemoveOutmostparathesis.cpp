class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ssd = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (cnt)
                {
                    ssd += s[i];
                    cnt++;
                }
                else
                {
                    cnt++;
                }
            }
            else
            {
                if (cnt > 1)
                {
                    ssd += s[i];
                    cnt--;
                }
                else
                {
                    cnt--;
                }
            }
        }
        return ssd;
    }
};