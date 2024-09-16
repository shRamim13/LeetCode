class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Handle empty input
        if (intervals.empty())
            return {};

        vector<vector<int>> v;
        // Sort the intervals by their starting values
        sort(intervals.begin(), intervals.end());

        // Start by adding the first interval
        v.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            // Use a reference to the last merged interval
            vector<int> &last = v.back();

            // Check if the current interval overlaps with the last merged
            // interval
            if (last[1] >= intervals[i][0])
            {
                // Merge the intervals by updating the end of the last merged
                // interval
                last[1] = max(last[1], intervals[i][1]);
            }
            else
            {
                // If no overlap, add the current interval to the result
                v.push_back(intervals[i]);
            }
        }

        return v;
    }
};
