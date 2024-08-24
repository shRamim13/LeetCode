class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int lt_mx = 0;
        int rt_mx = 0;
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l < r)
        {
            if (lt_mx < height[l])
            {
                lt_mx = max(lt_mx, height[l]);
            }
            if (rt_mx < height[r])
            {
                rt_mx = max(rt_mx, height[r]);
            }
            if (lt_mx < rt_mx)
            {
                ans += lt_mx - height[l];
                l++;
            }
            else
            {
                ans += rt_mx - height[r];
                r--;
            }
        }
        return ans;
    }
};