class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        s = s + s;
        bool ans = false;
        ans = s.find(goal) != string::npos;
        return ans;
    }
};