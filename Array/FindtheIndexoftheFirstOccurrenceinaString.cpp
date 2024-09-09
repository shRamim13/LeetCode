class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        if (haystack == needle)
        {
            return 0;
        }
        int indx = -1;
        int i = 0;
        int j = 0;
        int n = haystack.size();
        while (i < n)
        {
            if (needle[j] == haystack[i])
            {
                if (j == 0)
                {
                    indx = i;
                }
                if (j == needle.size() - 1)
                {
                    return indx;
                }
                i++, j++;
            }
            else
            {
                if (j > 0)
                {
                    j = 0;
                    i = indx + 1;
                }
                else
                {
                    i++;
                }
                indx = -1;
            }
        }
        return -1;
    }
};