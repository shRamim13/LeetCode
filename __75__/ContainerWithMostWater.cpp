class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            area = max(area, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return area;
    }
};