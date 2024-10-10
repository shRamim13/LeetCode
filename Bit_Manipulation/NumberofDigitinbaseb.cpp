#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, b;

    // Input the number and base
    cout << "Enter a positive integer (n): ";
    cin >> n;
    cout << "Enter a base (b > 1): ";
    cin >> b;

    // Check for valid input
    if (n <= 0 || b <= 1)
    {
        cout << "Number must be greater than 0 and base must be greater than 1." << endl;
        return 1; // Return with an error code
    }

    // Calculate the number of digits
    int ans = static_cast<int>(log(n) / log(b)) + 1;

    cout << "Number of digits of " << n << " in base " << b << " is: " << ans << endl;
    return 0;
}
