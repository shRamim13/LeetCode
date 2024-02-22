class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = 2 * nums.size();
        int cnt = 2 * n;
        vector<int> v;
        int ps = 0, ng = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (n % 2 == 0)
            {
                while (ps < n && nums[ps] < 0)
                {
                    ps++;
                }
                if (ps < n)
                {
                    v.push_back(nums[ps]);
                    ps++;
                    n--;
                }
            }
            else
            {
                while (ng < n && nums[ng] > 0)
                {
                    ng++;
                }
                if (ng < n)
                {
                    v.push_back(nums[ng]);
                    ng++;
                    n--;
                }
            }
        }
        return v;
    }
};
