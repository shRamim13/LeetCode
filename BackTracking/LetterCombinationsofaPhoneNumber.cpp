class Solution
{
public:
    void solve(string &digits, vector<string> &v,
               unordered_map<char, string> &mp, int indx, string s)
    {
        if (indx == digits.size())
        {
            v.push_back(s);
            return;
        }
        for (auto x : mp[digits[indx]])
        {
            solve(digits, v, mp, indx + 1, s + x);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> v;
        solve(digits, v, mp, 0, "");
        return v;
    }
};