class Solution
{
public:
    double myPow(double x, int N)
    {
        if (N == 0)
        {
            return 1;
        }
        long long n = N;
        if (N < 0)
        {
            x = 1 / x;
            n = -n;
        }

        double ans = 1.0;
        while (n)
        {
            if (n % 2)
            {
                ans *= x;
            }
            x = x * x;
            n = n / 2;
        }
        return ans;
    }
};