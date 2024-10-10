#include <iostream>

using namespace std;

// Function to check if a number is a power of two
bool isPowerOfTwo(int n)
{
    return (n > 0) && (n & (n - 1)) == 0; // Using bitwise operation
}

// Function to check if a number is odd or even
string oddOrEven(int n)
{
    return (n % 2 == 0) ? "Even" : "Odd";
}

// Function to calculate the power of a number using bitwise operations
int power(int base, int exponent)
{
    int result = 1;

    while (exponent > 0)
    {
        if (exponent & 1)
        { // Check if exponent is odd
            result *= base;
        }
        base *= base;   // Square the base
        exponent >>= 1; // Right shift exponent (divide by 2)
    }

    return result;
}

int main()
{
    int num, base, exponent;

    // Check if a number is a power of two
    cout << "Enter a number to check if it's a power of two: ";
    cin >> num;
    cout << num << " is " << (isPowerOfTwo(num) ? "a power of two." : "not a power of two.") << endl;

    // Check if a number is odd or even
    cout << "Enter a number to check if it's odd or even: ";
    cin >> num;
    cout << num << " is " << oddOrEven(num) << "." << endl;

    // Calculate the power of a number
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << base << " raised to the power of " << exponent << " is: " << power(base, exponent) << endl;

    return 0;
}
