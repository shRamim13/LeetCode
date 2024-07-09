class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int s_indx, vector<string> &v, string s,
               vector<vector<string>> &ans)
    {
        if (s_indx == s.size())
        {
            ans.push_back(v);
            return;
        }
        for (int e_indx = s_indx; e_indx < s.size(); e_indx++)
        {
            if (isPalindrome(s, s_indx, e_indx))
            {
                v.push_back(s.substr(s_indx, e_indx - s_indx + 1));
                solve(e_indx + 1, v, s, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, v, s, ans);
        return ans;
    }
};