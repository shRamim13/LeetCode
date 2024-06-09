class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int prefixSum = 0;
        int cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if (mod < 0)
            {
                mod += k;
            }
            if (mp[mod])
            {
                cnt += mp[mod];
                mp[mod]++;
            }
            else
            {
                mp[mod] = 1;
            }
        }
        return cnt;
    }
};