#include <iostream>
using namespace std;

void bitManipulation(int num, int i)
{
    // Get the value of the ith bit
    cout << (num & (1 << i)) << " ";

    // Set the ith bit
    cout << (num | (1 << i)) << " ";

    // Clear the ith bit
    cout << (num & ~(1 << i)) << " ";
}

int main()
{
    // Test case
    int num = 13; // Binary: 1101
    int i = 1;    // Manipulate the 2nd bit (zero-based indexing)

    bitManipulation(num, i);

    return 0;
}
