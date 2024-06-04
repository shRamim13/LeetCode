class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i] - '0']++;
        }
        int flag = 0;
        int odd = 0;
        int even = 0;
        for (auto x : mp)
        {
            int t = x.second;
            if (t % 2 == 0)
            {
                even += t;
            }
            else
            {
                odd += t - 1;
                flag = 1;
            }
        }

        return (flag) ? (even + odd) + 1 : (even + odd);
    }
};
