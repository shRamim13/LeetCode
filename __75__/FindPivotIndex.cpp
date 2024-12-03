class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int lft = 0;
        int total = 0;
        for (auto x : nums)
        {
            total += x;
        }
        for (int indx = 0; indx < nums.size(); indx++)
        {
            if (lft == total - lft - nums[indx])
            {
                return indx;
            }
            lft += nums[indx];
        }
        return -1;
    }
};