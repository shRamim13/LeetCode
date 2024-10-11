class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        // Keep dividing n by powers of 5 and add the result to count
        while (n >= 5)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};
