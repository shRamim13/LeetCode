#include <bits/stdc++.h>
using namespace std;

void permutation(int indx, vector<int> freq, vector<int> nums, vector<int> v, vector<vector<int>> ans)
{
    if (v.size() == nums.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            v.push_back(nums[i]);
            freq[i] = 1;
            permutation(i, freq, nums, v, ans);
            v.pop_back();
            freq[i] = 0;
        }
    }
}

int main()
{
    int n;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x ;
         nums.push_back(x);
    }
    vector<int> v;
    vector<vector<int>> ans;
    vector<int> freq(n, 0);
    permutation(0, freq, nums, v, ans);
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