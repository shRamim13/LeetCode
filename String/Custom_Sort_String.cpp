class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> mp;
        string ans = "", man = "";
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i + 1;
        }
        for (char ch : s)
        {
            if (mp.count(ch))
            {
                ans += ch;
            }
            else
            {
                man += ch;
            }
        }

        sort(ans.begin(), ans.end(),
             [&](char a, char b)
             { return mp[a] < mp[b]; });

        return ans + man;
    }
};
