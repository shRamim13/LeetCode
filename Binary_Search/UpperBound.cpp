#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &v, int s)
{
    int l = 0, r = v.size() - 1;
    int ans = r + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] >= s)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int val = lower_bound(v, s);
    cout << "Lower Bound is at " << val << " th index"
         << " and the value is "
         << v[val];
    return 0;
}