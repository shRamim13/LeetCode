class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int maxDis = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxDis < i)
            {
                return false;
            }
            maxDis = max(maxDis, i + nums[i]);
        }
        return true;
    }
};