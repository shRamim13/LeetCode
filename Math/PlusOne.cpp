class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> v;
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            v.push_back((digits[i] + c) % 10);
            c = (digits[i] + c) / 10;
        }
        if (c == 1)
        {
            v.push_back(1);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};