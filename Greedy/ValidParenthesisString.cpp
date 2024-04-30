class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> st;
        stack<int> ast;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == '*')
            {
                ast.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else if (!ast.empty())
                {
                    ast.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while (!st.empty())
        {
            if (ast.empty())
            {
                return false;
            }
            else if (st.top() < ast.top())
            {
                st.pop();
                ast.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};