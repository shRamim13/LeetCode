class Solution
{
public:
    int calculate(string s)
    {
        int number = 0, digit = 0, sign = 1;
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                digit = digit * 10 + (ch - '0');
            }
            else if (ch == '+')
            {
                number += sign * digit;
                digit = 0;
                sign = 1;
            }
            else if (ch == '-')
            {
                number += sign * digit;
                digit = 0;
                sign = -1;
            }
            else if (ch == '(')
            {
                number += sign * digit;
                st.push(number);
                st.push(sign);
                digit = 0;
                sign = 1;
                number = 0;
            }
            else if (ch == ')')
            {
                number += sign * digit;
                number *= st.top();
                st.pop();
                number += st.top();
                st.pop();
                digit = 0;
                sign = 1;
            }
        }
        number += sign * digit;
        return number;
    }
};