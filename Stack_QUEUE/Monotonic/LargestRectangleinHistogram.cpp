class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        stack<int> st;
        int n = heights.size();
        vector<int> pse(n, 0);
        vector<int> nse(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            pse[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }

        while (st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            nse[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (nse[i] - pse[i] - 1) * heights[i]);
        }
        return ans;
    }
};