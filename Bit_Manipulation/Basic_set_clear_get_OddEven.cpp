#include <iostream>
using namespace std;

void bitManipulation(int num, int i)
{
    // Get/check the value of the ith bit
    cout << (num & (1 << i)) << " ";

    // Set the ith bit
    cout << (num | (1 << i)) << " ";

    // Clear the ith bit
    cout << (num & ~(1 << i)) << "\n";
}

string oddEven(int N)
{
    return (N & 1) ? "odd" : "even";
}

void exchange_A_B(int a, int b)
{

    cout << "Before " << a << " " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After " << a << " " << b << endl;
}

int main()
{
    // Test case
    int num = 13; // Binary: 1101
    int i = 1;    // Manipulate the 2nd bit (zero-based indexing)

    bitManipulation(num, i);
    cout << oddEven(num) << endl;
    exchange_A_B(4, 9);
    return 0;
}

// a=4   100
// b=7   111

// a=a^b 011

// b=a^b 100

// a=a^b 111

// a=a+b 13

// b=a-b; 4

// a=a-b 7