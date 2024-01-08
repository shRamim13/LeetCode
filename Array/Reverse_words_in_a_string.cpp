class Solution
{
public:
    string trim(string &str)
    {
        int fs = str.find_first_not_of(" ");
        int ls = str.find_last_not_of(" ");
        return str.substr(fs, ls - fs + 1);
    }

    string reverseWords(string s)
    {
        string str;
        stack<string> stk;
        string st = trim(s);
        string word;

        for (char ch : st)
        {
            if (ch == ' ')
            { /// string can't handle
                if (!word.empty())
                {
                    stk.push(word);
                    word = "";
                }
            }
            else
            {
                word += ch;
            }
        }
        if (!word.empty())
        { // handling last word
            stk.push(word);
        }

        while (!stk.empty())
        {
            str += stk.top();
            stk.pop();
            if (!stk.empty())
            {
                str += " ";
            }
        }
        return str;
    }
};