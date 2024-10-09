class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (auto x : nums)
            {
                if (x & 1 << i)
                {
                    cnt++;
                }
            }
            if (cnt % 3 != 0)
            {
                result |= 1 << i;
            }
        }
        return result;
    }
};