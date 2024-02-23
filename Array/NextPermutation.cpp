class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int indx = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                indx = i;
                break;
            }
        }
        if (indx == -1)
        {
            sort(nums.begin(), nums.end());
        }
        else
        {
            for (int i = nums.size() - 1; i >= indx; i--)
            {
                if (nums[i] > nums[indx])
                {
                    swap(nums[i], nums[indx]);
                    break;
                }
            }
            sort(nums.begin() + indx + 1, nums.end());
        }
    }
};