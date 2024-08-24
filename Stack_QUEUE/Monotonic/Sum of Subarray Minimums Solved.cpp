class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> pse(n, 0);
        vector<int> nse(n, 0);
        long long ans = 0;
        long long mod = 1e9 + 7;
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
            ans = (ans + (sum * arr[i]) % mod) % mod;
        }
        return ans;
    }
};
