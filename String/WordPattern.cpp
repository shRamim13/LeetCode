class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> char_map;
        unordered_map<string, char> word_map;
        stringstream s(str);
        string word;
        int i = 0;
        while (s >> word)
        {
            if (i == pattern.size() ||
                (char_map.count(pattern[i]) && char_map[pattern[i]] != word) ||
                (word_map.count(word) && word_map[word] != pattern[i]))
            {
                return false;
            }
            char_map[pattern[i]] = word;
            word_map[word] = pattern[i];
            i++;
        }
        return i == pattern.size();
    }
};