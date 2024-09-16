class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        v.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> hlp = v.back();
            if (hlp[1] >= intervals[i][0])
            {
                hlp[1] = max(hlp[1], intervals[i][1]);
                v.pop_back();
                v.push_back(hlp);
            }
            else
            {
                v.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return v;
    }
};
