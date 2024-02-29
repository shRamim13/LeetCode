class Solution
{
public:
    bool _is_Bouquet_Possible(vector<int> &bloomDay, int mid, int m, int k)
    {
        int BouquetCnt = 0;
        int flowerBloom = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                flowerBloom++;
            }
            else
            {
                BouquetCnt += flowerBloom / k;
                flowerBloom = 0;
            }
        }
        BouquetCnt += flowerBloom / k;
        return BouquetCnt >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long ans = 1LL * m * k;
        if (bloomDay.size() < ans)
            return -1;
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            l = min(l, bloomDay[i]);
            r = max(r, bloomDay[i]);
        }
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (_is_Bouquet_Possible(bloomDay, mid, m, k))
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