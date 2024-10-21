class Solution
{
public:
    int _gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        return _gcd(b % a, a);
    }
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        int gcd = _gcd(str2.size(), str1.size());
        return str1.substr(0, gcd);
    }
};