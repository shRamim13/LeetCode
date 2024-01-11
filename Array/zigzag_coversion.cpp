class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> v(numRows);
        if (numRows == 1)
        {
            return s;
        }
        bool flag = false;
        string ans = "";
        int i = 0;
        for (auto ch : s)
        {
            v[i] += ch;
            if (i == 0 || i == numRows - 1)
            {
                flag = !flag;
            }
            if (flag)
            {
                i++;
            }
            else
            {
                i--;
            }
        }
        for (auto k : v)
        {
            ans += k;
            
        }
        return ans;
    }
};