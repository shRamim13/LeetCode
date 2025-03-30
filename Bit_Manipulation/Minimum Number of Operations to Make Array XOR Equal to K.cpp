class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int x : nums)
        {
            ans ^= x;
        }
        ans ^= k;
        int cnt = 0;
        while (ans)
        {
            ans = ans & (ans - 1);
            cnt++;
        }
        return cnt;
    }
};