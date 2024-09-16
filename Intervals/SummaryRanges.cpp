class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> v;
        if (nums.size() == 0)
        {
            return v;
        }
        string start = to_string(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] + 1 != nums[i])
            {
                if (start == to_string(nums[i - 1]))
                {
                    v.push_back(to_string(nums[i - 1]));
                }
                else
                {
                    v.push_back(start + "->" + to_string(nums[i - 1]));
                }
                start = to_string(nums[i]);
            }
        }
        if (start == to_string(nums.back()))
        {
            v.push_back(to_string(nums.back()));
        }
        else
        {
            v.push_back(start + "->" + to_string(nums.back()));
        }
        return v;
    }
};
