class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate(result, "", 0, 0, n);
        return result;
    }

    void generate(vector<string> &result, string current, int open, int close,
                  int max)
    {
        if (current.length() == max * 2)
        {
            result.push_back(current);
            return;
        }
        if (open < max)
        {
            generate(result, current + "(", open + 1, close, max);
        }
        if (close < open)
        {
            generate(result, current + ")", open, close + 1, max);
        }
    }
};
