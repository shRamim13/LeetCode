#include <iostream>
using namespace std;

// Function to compute GCD
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

// Function to compute both GCD and LCM
void gcd_lcm(int a, int b)
{
    int gcdValue = gcd(a, b);
    int lcmValue = (a * b) / gcdValue;

    cout << "GCD: " << gcdValue << endl;
    cout << "LCM: " << lcmValue << endl;
}

int main()
{
    int a = 12, b = 18;
    gcd_lcm(a, b);
    return 0;
}
