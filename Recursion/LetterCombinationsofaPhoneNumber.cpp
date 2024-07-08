class Solution
{
public:
    void solve(int indx, string s, string &digits, vector<string> &ans,
               unordered_map<char, string> &mp)
    {
        if (indx == digits.size())
        {
            ans.push_back(s);
            return;
        }
        string t = mp.at(digits[indx]);
        for (auto x : t)
        {
            solve(indx + 1, s + x, digits, ans, mp);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        if (digits.empty())
            return ans;
        solve(0, "", digits, ans, mp);
        return ans;
    }
};
