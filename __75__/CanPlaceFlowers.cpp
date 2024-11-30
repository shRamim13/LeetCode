class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                int lt = (i == 0 || flowerbed[i - 1] == 0);
                int rt = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                if (lt && rt)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};