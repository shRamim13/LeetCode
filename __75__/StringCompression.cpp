class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        int j = 0;

        int n = chars.size();
        while (i < n)
        {
            int cnt = 0;
            char ch = chars[i];
            while (i < n && chars[i] == ch)
            {
                i++;
                cnt++;
            }
            chars[j++] = ch;
            if (cnt > 1)
            {
                string s = to_string(cnt);
                for (auto x : s)
                {
                    chars[j++] = x;
                }
            }
        }
        return j;
    }
};