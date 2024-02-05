#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> nums.push_back(x);
    }
    vector<int> v;
    vector<vector<int>> ans;
    permutation(0, nums, v, ans);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}