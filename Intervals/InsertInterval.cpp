class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {

        vector<vector<int>> ans;
        int i = 0;
        for (i = 0; i < intervals.size(); i++)
        {
            if (newInterval[0] > intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else if (newInterval[1] < intervals[i][0])
            {
                break;
            }
            else
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        ans.push_back(newInterval);
        while (i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
