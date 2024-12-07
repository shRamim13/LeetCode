class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string cur_str = "";
                while (st.top() != '[')
                {
                    cur_str = st.top() + cur_str;
                    st.pop();
                }
                st.pop();
                string num = "";
                while (!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }
                int tym = stoi(num);
                while (tym--)
                {
                    for (auto x : cur_str)
                    {
                        st.push(x);
                    }
                }
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};