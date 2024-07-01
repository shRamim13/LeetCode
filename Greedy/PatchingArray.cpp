class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long formedSum = 0;
        int expectedSum = 1;
        int minpatch = 0;
        int i = 0;
        int sz = nums.size();
        while (formedSum < n)
        {
            if (i < sz && nums[i] <= expectedSum)
            {
                formedSum += nums[i];
                i++;
            }
            else
            {
                minpatch++;
                formedSum += expectedSum;
            }
            expectedSum = formedSum + 1;
        }

        return minpatch;
    }
};
