class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if (mod < 0)
            {
                mod += k;
            }
            if (mp.count(mod))
            {
                if (i - mp[mod] >= 2)
                {
                    return true;
                }
            }
            else
            {
                mp[mod] = i;
            }
        }
        return false;
    }
};
