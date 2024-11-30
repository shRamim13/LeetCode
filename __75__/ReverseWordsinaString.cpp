class Solution
{
public:
    string reverseWords(string s)
    {
        int lt = 0;
        int rt = s.size();
        string tmp = "";
        string ans = "";
        while (lt < rt)
        {
            if (s[lt] != ' ')
            {
                tmp += s[lt];
            }
            else
            {
                if (!tmp.empty())
                {
                    ans = (ans.empty()) ? tmp : tmp + " " + ans;
                    tmp = "";
                }
            }
            lt++;
        }
        if (!tmp.empty())
        {
            ans = (ans.empty()) ? tmp : tmp + " " + ans;
        }
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
//};

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {

//         reverse(s.begin(), s.end());

//         int i = 0;
//         int l = 0, r = 0;

//         int n = s.length();

//         while (i < n)
//         {
//             while (i < n && s[i] != ' ')
//             {
//                 s[r++] = s[i++];
//             }

//             if (l < r)
//             {
//                 reverse(s.begin() + l, s.begin() + r);

//                 s[r] = ' ';
//                 r++;

//                 l = r;
//             }

//             i++;
//         }

//         s = s.substr(0, r - 1);

//         return s;
//     }
// };

/*

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";

        string result = "";
        while (ss >> token) {
            result = token + " " + result;
        }
        return result.substr(0, result.length() - 1);
    }
};
*/