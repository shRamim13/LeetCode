class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int indx = 0;
        int i = 0;

        while (i < chars.size())
        {
            int cnt = 0;
            char cur_char = chars[i];
            while (i < chars.size() && chars[i] == cur_char)
            {
                i++;
                cnt++;
            }
            chars[indx++] = cur_char;

            if (cnt > 1)
            {
                string s = to_string(cnt);
                for (auto x : s)
                {
                    chars[indx++] = x;
                }
            }
        }
        return indx;
    }
};