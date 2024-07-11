class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char ch : s)
        {
            if (ch == 'c')
            {
                if (st.size() >= 2)
                {
                    char second = st.top();
                    st.pop();
                    char first = st.top();
                    st.pop();
                    if (first != 'a' || second != 'b')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
