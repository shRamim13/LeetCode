#include <bits/stdc++.h>
void _sort(stack<int> &st, int element)
{
    if (st.empty() || st.top() < element)
    {
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    _sort(st, element);
    st.push(top);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();
    sortStack(st);
    _sort(st, top);
}