class Solution
{
public:
    int _divisor(vector<int> &nums, int s)
    {
        int cnt = 0;
        for (auto x : nums)
        {
            cnt += (x + s - 1) / s;
        }
        return cnt;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (_divisor(nums, mid) <= threshold)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};