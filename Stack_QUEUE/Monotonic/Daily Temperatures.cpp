class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> nxtGreater;
        vector<int> v(n, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            while (!nxtGreater.empty() && temperatures[i] >= temperatures[nxtGreater.top()])
            {
                nxtGreater.pop();
            }
            if (!nxtGreater.empty())
            {
                v[i] = nxtGreater.top() - i;
            }
            else
            {
                v[i] = 0;
            }
            nxtGreater.push(i);
        }
        return v;
    }
};
