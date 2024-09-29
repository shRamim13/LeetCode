class Trie
{
public:
    Trie *child[26];
    bool flag;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        flag = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (auto x : word)
        {
            int indx = x - 'a';
            if (node->child[indx] == nullptr)
            {
                node->child[indx] = new Trie();
            }
            node = node->child[indx];
        }
        node->flag = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (auto x : word)
        {
            int indx = x - 'a';
            if (node->child[indx] == nullptr)
            {
                return false;
            }
            node = node->child[indx];
        }
        return node->flag;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (auto x : prefix)
        {
            int indx = x - 'a';
            if (node->child[indx] == nullptr)
            {
                return false;
            }
            node = node->child[indx];
        }
        return true;
    }
};
