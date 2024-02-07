#include <bits/stdc++.h>
using namespace std;
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

    // for (int i = 0; i < n; i++)
    // {
    //     cout << prev_min[i] << " ";
    // }
    // cout << endl;

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

    // for (int i = 0; i < n; i++)
    // {
    //     cout << next_min[i] << " ";
    // }
    // cout << endl;

    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int temp = (next_min[i] - prev_min[i] - 1) * heights[i];
        // cout << next_min[i] << " " << prev_min[i] << " " << heights[i] << " " << temp << endl;
        maxArea = max(temp, maxArea);
    }

    return maxArea;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i]=x;
    }
    cout << largestRectangleArea(v) << endl;
    return 0;
}