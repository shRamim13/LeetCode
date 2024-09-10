class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minSize = INT_MAX;
        int i = 0;
        int j = nums.size();
        int sum = 0;
        int indx = 0;
        while (i < j)
        {
            sum += nums[i];
            if (sum < target)
            {
                i++;
            }
            else
            {
                while (sum >= target)
                {
                    minSize = min(minSize, i - indx + 1);
                    sum -= nums[indx];
                    indx++;
                }
                i++;
            }
        }
        return (minSize == INT_MAX) ? 0 : minSize;
    }
};