class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        while (i < n)
        {
            int target = -1 * nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    };
                    while (l < r && nums[r] == nums[r - 1])
                    {
                        r--;
                    };
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
            {
                i++;
            }
            i++;
        }
        return ans;
    }
};