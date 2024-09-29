class WordDictionary
{
public:
    WordDictionary *child[26];
    bool flag;
    WordDictionary()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        flag = false;
    }

    void addWord(string word)
    {
        WordDictionary *node = this;
        for (auto x : word)
        {
            int indx = x - 'a';
            if (node->child[indx] == nullptr)
            {
                node->child[indx] = new WordDictionary();
            }
            node = node->child[indx];
        }
        node->flag = true;
    }

    bool helper(string word, WordDictionary *node, int cnt)
    {
        if (cnt == word.size())
        {
            return node->flag;
        }
        char ch = word[cnt];
        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->child[i] != nullptr)
                {
                    if (helper(word, node->child[i], cnt + 1))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        else
        {
            int indx = ch - 'a';
            if (node->child[indx] == nullptr)
            {
                return false;
            }
            return helper(word, node->child[indx], cnt + 1);
        }
    }

    bool search(string word) { return helper(word, this, 0); }
};
