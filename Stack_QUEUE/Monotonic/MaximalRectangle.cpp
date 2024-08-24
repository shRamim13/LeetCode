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

        while (!st.empty())
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int ans = 0;
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int> v(col, 0);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '1')
                {
                    v[j] += 1;
                }
                else
                {
                    v[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(v));
        }
        return ans;
    }
};