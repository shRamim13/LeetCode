class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int helper = prefixSum - k;
            if (mp[helper])
            {
                cnt += mp[helper];
                mp[prefixSum]++;
            }
            else
            {
                mp[prefixSum]++;
            }
        }
        return cnt;
    }
};
