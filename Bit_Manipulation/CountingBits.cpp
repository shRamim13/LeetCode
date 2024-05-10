class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            int num = i;
            while (num > 0)
            {
                cnt++;
                num = num & (num - 1);
            }
            v[i] = cnt;
        }
        
        return v;
    }
};
