class Solution
{
public:
    long long mod = 1e9 + 7;
    long long pow(long long num, long long p)
    {
        if (p == 0)
        {
            return 1;
        }
        long long temp = pow(num, p / 2);
        if (p % 2 == 0)
        {
            return (temp * temp) % mod;
        }
        else
        {
            return (num * temp * temp) % mod;
        }
    }
    int countGoodNumbers(long long n)
    {
        long long odd = (n / 2);
        long long even = (n / 2) + (n % 2);
        return (pow(5, even) % mod * pow(4, odd) % mod) % mod;
    }
};