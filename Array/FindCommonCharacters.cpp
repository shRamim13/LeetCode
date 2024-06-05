class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> minFreq(26, INT_MAX);
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> charFreq(26, 0);
            for (char c : words[i])
            {
                charFreq[c - 'a']++;
            }
            for (int j = 0; j < 26; j++)
            {
                minFreq[j] = min(minFreq[j], charFreq[j]);
            }
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++)
        {
            while (minFreq[i] > 0 && minFreq[i] != INT_MAX)
            {
                ans.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }

        return ans;
    }
};
