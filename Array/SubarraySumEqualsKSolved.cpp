class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int preSum = 0, cnt = 0;
        for (auto x : nums)
        {
            preSum += x;
            int temp = preSum - k;
            cnt += mp[temp];
            mp[preSum]++;
        }
        return cnt;
    }
};