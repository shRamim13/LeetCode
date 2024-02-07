#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == '0')
                {
                    heights[j] = 0;
                }
                else
                {
                    heights[j]++;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prev_min(n);
        vector<int> next_min(n);
        stack<int> s1, s2;

        for (int i = 0; i < n; i++)
        {
            while (!s1.empty() && heights[s1.top()] >= heights[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                prev_min[i] = -1;
            }
            else
            {
                prev_min[i] = s1.top();
            }
            s1.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s2.empty() && heights[s2.top()] >= heights[i])
            {
                s2.pop();
            }
            if (s2.empty())
            {
                next_min[i] = n;
            }
            else
            {
                next_min[i] = s2.top();
            }
            s2.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = (next_min[i] - prev_min[i] - 1) * heights[i];
            maxArea = max(temp, maxArea);
        }

        return maxArea;
    }
};
