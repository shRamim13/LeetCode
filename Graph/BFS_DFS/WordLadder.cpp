class Solution
{
public:
    int ladderLength(string startWord, string endWord, vector<string> &bank)
    {
        unordered_set<string> mp(bank.begin(), bank.end());
        unordered_set<string> vis;
        queue<string> q;
        q.push(startWord);
        vis.insert(startWord);
        int steps = 1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string s = q.front();
                q.pop();
                if (s == endWord)
                {
                    return steps;
                }
                for (char x = 'a'; x <= 'z'; x++)
                {
                    for (int i = 0; i < s.size(); i++)
                    {
                        string ssd = s;
                        ssd[i] = x;
                        if (vis.find(ssd) == vis.end() &&
                            mp.find(ssd) != mp.end())
                        {
                            q.push(ssd);
                            vis.insert(ssd);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};ad