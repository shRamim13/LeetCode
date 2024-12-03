class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxi = 0;
        int val = 0;
        for (auto x : gain)
        {
            val += x;
            maxi = max(val, maxi);
        }
        return maxi;
    }
};