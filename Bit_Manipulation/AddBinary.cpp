class Solution
{
public:
    string addBinary(string a, string b)
    {
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        string s = "";
        while (m >= 0 || n >= 0 || carry != 0)
        {
            int sum = 0;
            if (m >= 0)
            {
                sum += a[m--] - '0';
            }
            if (n >= 0)
            {
                sum += b[n--] - '0';
            }
            sum += carry;
            s += (sum % 2 + '0');
            carry = sum / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};