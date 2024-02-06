class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        vector<int> Left(n, 0);
        vector<int> Right(n, 0);
        Left[0] = height[0];
        Right[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            Left[i] = max(height[i], Left[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            Right[i] = max(height[i], Right[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            ans += min(Left[i], Right[i]) - height[i];
        }
        return ans;
    }
};