#include <bits/stdc++.h> 
using namespace std;

class Solution
{
public:
    void generateStrings(int n, string current, vector<string> &result)
    {
        // Base case: if the current string length is n, add it to the result
        if (current.length() == n)
        {
            result.push_back(current);
            return;
        }

        // Add '0' and recursively call the function
        generateStrings(n, current + "0", result);

        // Add '1' and recursively call the function only if the last character is not '1'
        if (current.empty() || current.back() != '1')
        {
            generateStrings(n, current + "1", result);
        }
    }

    vector<string> generateBinaryStrings(int n)
    {
        vector<string> result;
        generateStrings(n, "", result);
        return result;
    }
};

int main()
{
    Solution solution;
    int n = 5; // Length of the binary strings
    vector<string> binaryStrings = solution.generateBinaryStrings(n);

    for (const string &str : binaryStrings)
    {
        cout << str << endl;
    }

    return 0;
}
