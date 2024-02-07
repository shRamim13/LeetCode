#include <bits/stdc++.h>
using namespace std;

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
    cout << "Left Maximum -> " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << Left[i] << " ";
    }
    cout << endl;
    for (int i = n - 2; i >= 0; i--)
    {
        Right[i] = max(height[i], Right[i + 1]);
    }

    cout << "Right Maximum -> " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << Right[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        ans += min(Left[i], Right[i]) - height[i];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Mximum trapped Water  --> " << trap(v) << endl;
}