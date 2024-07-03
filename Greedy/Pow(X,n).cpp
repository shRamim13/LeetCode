class Solution
{
public:
    double myPow(double x, int n)
    {
        // Handle the special case when n is the most negative number
        // which cannot be directly negated
        if (n == INT_MIN)
        {
            return 1 / (myPow(x, INT_MAX) * x);
        }

        // If n is negative, compute the positive power and take the reciprocal
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        return powHelper(x, n);
    }

private:
    double powHelper(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        double half = powHelper(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};
