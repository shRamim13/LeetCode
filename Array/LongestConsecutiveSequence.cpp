class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int cnt = 0;
        int longest = 1;
        int lastMin = INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == lastMin)
            {
                cnt++;
                lastMin = nums[i];
            }
            else if (lastMin != nums[i])
            {
                cnt = 1;
                lastMin = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};
