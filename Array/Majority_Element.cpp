class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0) // handle empty vector
            return -1;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        n = n / 2;
        for (auto x : mp)
        {
            if (x.second > n)
                return x.first;
        }

        return -1;
    }
};
