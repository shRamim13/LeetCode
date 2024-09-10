class Solution
{
public:
    string _createLine(int i, int j, int n, int needed_space, int xtra_space,
                       int maxWidth, vector<string> &words)
    {
        string s = "";
        for (int k = i; k < j; k++)
        {
            s += words[k];
            if (k == j - 1)
            {
                break;
            }
            for (int p = 0; p < needed_space; p++)
            {
                s += " ";
            }
            if (xtra_space)
            {
                s += " ";
                xtra_space--;
            }
        }
        while (s.size() < maxWidth)
        {
            s += " ";
        }
        return s;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int i = 0;
        int j = 0;
        int space = 0;
        int total_char = 0;
        int remaining_space = 0;
        int n = words.size();
        while (i < n)
        {
            total_char = words[i].size();
            space = 0;
            j = i + 1;
            while (j < n &&
                   words[j].size() + 1 + space + total_char <= maxWidth)
            {
                total_char += words[j].size();
                space++;
                j++;
            }
            int needed_space =
                (space == 0) ? 0 : (maxWidth - total_char) / space;
            int xtra_space = (space == 0) ? 0 : (maxWidth - total_char) % space;

            if (j == n)
            {
                needed_space = 1;
                xtra_space = 0;
            }
            ans.push_back(_createLine(i, j, n, needed_space, xtra_space,
                                      maxWidth, words));
            i = j;
        }
        return ans;
    }
};