class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> counts;

        for (char ch : magazine)
            counts[ch]++;

        for (char ch : ransomNote)
        {
            if (counts[ch] == 0)
                return false;
            counts[ch]--;
        }

        return true;
    }
};