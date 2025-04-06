class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans = "";
        for (string &s : strs)
        {
            ans += to_string(s.size()) + "@" + s;
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> v;
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '@')
            {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            v.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return v;
    }
};
