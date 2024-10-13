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

/*#include <iostream>
using namespace std;

class Solution {
public:
    // Function to perform modular exponentiation
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;  // Initialize result
        base = base % mod;     // Handle base larger than mod
        
        while (exp > 0) {
            // If exp is odd, multiply base with the result
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            // Now exp must be even
            exp = exp >> 1;  // Divide exp by 2
            base = (base * base) % mod;  // Square the base
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Input base, exponent, and modulus
    long long base, exp, mod;
    cout << "Enter base, exponent, and modulus: ";
    cin >> base >> exp >> mod;

    // Calculate result
    long long result = sol.power(base, exp, mod);
    cout << base << "^" << exp << " mod " << mod << " = " << result << endl;

    return 0;
}
*/