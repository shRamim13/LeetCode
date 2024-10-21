class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> mp(bank.begin(), bank.end());
        unordered_set<string> vis;
        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string s = q.front();
                q.pop();
                if (s == endGene)
                {
                    return steps;
                }
                for (auto x : "ACGT")
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
        return -1;
    }
};