class Solution
{
public:
    long long subArrayRanges(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();

        // next smaller and previous smaller

        vector<int> pse(n, 0);
        vector<int> nse(n, 0);
        long long ans = 0;

        // pse
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
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

        // nse
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            nse[i] = (st.empty() ? n : st.top());
            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            long long ls = i - pse[i];
            long long rs = nse[i] - i;
            long long sum = ls * rs;
            ans += sum * arr[i];
        }

        while (!st.empty())
        {
            st.pop();
        }

        // next greater and previous greater

        vector<int> pge(n, 0);
        vector<int> nge(n, 0);
        long long ans1 = 0;

        // pge
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            pge[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        while (!st.empty())
        {
            st.pop();
        }

        // nge
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            nge[i] = (st.empty() ? n : st.top());
            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            long long ls = i - pge[i];
            long long rs = nge[i] - i;
            long long sum = ls * rs;
            ans1 += sum * arr[i];
        }

        return ans1 - ans;
    }
};
