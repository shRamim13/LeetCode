class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                if (!temp.empty())
                {
                    ans = temp + " " + ans;
                    temp = "";
                }
            }
        }
        ans = temp + " " + ans;
        if (ans[0] == ' ')
        {
            ans = ans.substr(1, ans.size());
        }
        ans = ans.substr(0, ans.size() - 1);

        return ans;
    }
};

// string trim(string &str)
// {
//     int fs = str.find_first_not_of(" ");
//     int ls = str.find_last_not_of(" ");
//     return str.substr(fs, ls - fs + 1);
// }

// string reverseWords(string s)
// {
//     string str;
//     stack<string> stk;
//     string st = trim(s);
//     string word;

//     for (char ch : st)
//     {
//         if (ch == ' ')
//         { /// string can't handle
//             if (!word.empty())
//             {
//                 stk.push(word);
//                 word = "";
//             }
//         }
//         else
//         {
//             word += ch;
//         }
//     }
//     if (!word.empty())
//     { // handling last word
//         stk.push(word);
//     }

//     while (!stk.empty())
//     {
//         str += stk.top();
//         stk.pop();
//         if (!stk.empty())
//         {
//             str += " ";
//         }
//     }
//     return str;
// }