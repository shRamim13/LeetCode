
class Solution
{
public:
    void helper(stack<int> &st, int element)
    {
        if (st.empty())
        {
            st.push(element);
            return;
        }
        int n = st.top();
        st.pop();
        helper(st, element);
        st.push(n);
    }

    void Reverse(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        int n = st.top();
        st.pop();
        Reverse(st);
        helper(st, n);
    }
};