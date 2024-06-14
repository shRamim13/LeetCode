class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
};

//  s[i]^=s[n-1-i];     // z=x^y
//  s[n-1-i]^=s[i];     // y=z^y=(x^y)^y=x
//  s[i]^=s[n-1-i];     // x=z^x=(x^y)^x=y