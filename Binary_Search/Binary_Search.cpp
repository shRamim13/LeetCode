#include <bits/stdc++.h>
using namespace std;

int _binary_search(vector<int> &v, int s)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - r) / 2;
        if (v[mid] == s)
            return mid;
        else if (v[mid] < s)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
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
    int val = _binary_search(v, s);
    if (val != -1)
    {
        cout << v[val] << " at " << val << " th index.";
    }
    else
    {
        cout << "Number not found";
    }
}