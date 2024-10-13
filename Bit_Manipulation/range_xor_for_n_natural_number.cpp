#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to compute the XOR from 1 to n
    int xorFrom1ToN(int n)
    {
        if (n % 4 == 0)
        {
            return n; // If n % 4 == 0, result is n
        }
        else if (n % 4 == 1)
        {
            return 1; // If n % 4 == 1, result is 1
        }
        else if (n % 4 == 2)
        {
            return n + 1; // If n % 4 == 2, result is n + 1
        }
        else
        {
            return 0; // If n % 4 == 3, result is 0
        }
    }

    // Function to compute the XOR from a to b
    int rangeXOR(int a, int b)
    {
        return xorFrom1ToN(b) ^ xorFrom1ToN(a - 1);
    }

    // Wrapper function to handle the range from 0 to n
    int xorToN(int n)
    {
        return xorFrom1ToN(n);
    }
};

int main()
{
    Solution sol;

    // Test case: XOR from 0 to 6
    int n1 = 6;
    cout << "XOR from 0 to " << n1 << " is: " << sol.xorToN(n1) << endl; // Output: 7

    // Test case: XOR from 2 to 6
    int a = 2, b = 6;
    cout << "XOR from " << a << " to " << b << " is: " << sol.rangeXOR(a, b) << endl; // Output: 6

    return 0;
}
