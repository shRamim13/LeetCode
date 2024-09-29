class Trie
{
public:
    Trie *child[26];
    string word;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        word = "";
    }

    void insert(string &s)
    {
        Trie *node = this;
        for (auto x : s)
        {
            int indx = x - 'a';
            if (node->child[indx] == nullptr)
            {
                node->child[indx] = new Trie();
            }
            node = node->child[indx];
        }
        node->word = s;
    }
};

class Solution
{
public:
    vector<string> ans;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void solve(vector<vector<char>> &board, int x, int y, Trie *root)
    {
        char ch = board[x][y];
        if (ch == '$' || root->child[ch - 'a'] == nullptr)
        {
            return;
        }

        root = root->child[ch - 'a'];
        if (root->word != "")
        {
            ans.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '$';

        for (auto [dx, dy] : directions)
        {
            int newX = x + dx, newY = y + dy;
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size())
            {
                solve(board, newX, newY, root);
            }
        }

        board[x][y] = ch;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = new Trie();
        for (auto &x : words)
        {
            root->insert(x);
        }

        int row = board.size();
        int column = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (root->child[board[i][j] - 'a'] != nullptr)
                {
                    solve(board, i, j, root);
                }
            }
        }
        return ans;
    }
};
