class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int n = start ^ goal;
        int cnt = 0;
        while (n > 0)
        {
            cnt++;
            n = (n - 1) & n;
        }
        return cnt;
    }
};

// 1010
// 1001
// 0011

// 1100
// 1111
// 0011

// 1001
// 0111
// 1110