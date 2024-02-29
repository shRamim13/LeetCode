class Solution
{
public:
    int _counting_bananas_eating_time(vector<int> &piles, int s)
    {
        int cnt = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            cnt += (piles[i] + s - 1) / s; // ceil value
        }
        return cnt;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int mid = -1;
        int l = 1;
        int r = 10000000000;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int cnt = _counting_bananas_eating_time(piles, mid);
            if (cnt <= h)
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
