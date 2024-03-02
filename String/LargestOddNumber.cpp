class Solution
{
public:
    string largestOddNumber(string num)
    {
        string s = "";
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2)
            {
                s = num.substr(0, i + 1);
                break;
            }
        }
        return s;
    }
};