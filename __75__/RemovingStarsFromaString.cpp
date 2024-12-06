class Solution
{
public:
    string removeStars(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '*')
                ans.push_back(s[i]);
            else
                ans.pop_back();
        }
        return ans;
    }
};

// class Solution {
// public:
//     string removeStars(string s) {
//         stack<char> st;
//         for (auto x : s) {
//             if (x == '*') {
//                 if (!st.empty()) {
//                     st.pop();
//                 }
//             } else {
//                 st.push(x);
//             }
//         }
//         string ssd = "";
//         while (!st.empty()) {
//             ssd += st.top();
//             st.pop();
//         }
//         reverse(ssd.begin(), ssd.end());
//         return ssd;
//     }
// };