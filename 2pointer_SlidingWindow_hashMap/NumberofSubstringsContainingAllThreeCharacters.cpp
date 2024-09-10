class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0;
        int hash[3] = {-1, -1, -1};
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
            if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1)
            {
                int min_index = min(hash[0], min(hash[1], hash[2]));
                cnt += min_index + 1;
            }
        }
        return cnt;
    }
};
