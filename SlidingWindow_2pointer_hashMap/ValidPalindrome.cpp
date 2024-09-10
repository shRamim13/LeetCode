class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + ('a' - 'A');
            }
        }
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (!isalnum(s[i]))
            {
                i++;
            }
            else if (!isalnum(s[j]))
            {
                j--;
            }
            else if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};