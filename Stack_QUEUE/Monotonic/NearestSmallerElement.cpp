vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> ans(A.size(), 0); // Initialize answer vector with the same size as A
    stack<int> st;

    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1; // No smaller element found
        }
        else
        {
            ans[i] = st.top(); // Previous smaller element
        }

        st.push(A[i]); // Push the current element onto the stack
    }

    return ans;
}
