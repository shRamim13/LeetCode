class MinStack
{
    stack<int> st, at;

public:
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        if (at.empty() || val <= at.top())
        {
            at.push(val);
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            if (!at.empty() && st.top() == at.top())
            {
                at.pop();
            }
            st.pop();
        }
        return;
    }

    int top()
    {
        if (!st.empty())
            return st.top();
        return -1;
    }

    int getMin()
    {
        if (!at.empty())
            return at.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */