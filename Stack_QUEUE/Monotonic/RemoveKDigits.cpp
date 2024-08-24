class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string s = ""; // Resultant string after removing digits
        for (int i = 0; i < num.size(); i++)
        {
            // Pop the last character from s while it is greater than num[i] and k > 0
            while (s.size() > 0 && s.back() > num[i] && k > 0)
            {
                s.pop_back();
                k--;
            }
            s += num[i];
        }

        // If k is still greater than 0, remove additional characters from the end of s
        while (k > 0)
        {
            s.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < s.size() && s[start] == '0')
        {
            start++;
        }

        s = s.substr(start); // Remove leading zeros by taking the substring

        // If s is empty after removing leading zeros, return "0"
        return s.empty() ? "0" : s;
    }
};
