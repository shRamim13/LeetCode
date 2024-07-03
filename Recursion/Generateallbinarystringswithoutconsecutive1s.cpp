#include <bits/stdc++.h>
using namespace std;

void solve(int n, string temp, vector<string> &ans)
{
    if (n == temp.size())
    {
        ans.push_back(temp);
        return;
    }
    solve(n, temp + '0', ans);
    if (temp.size() == 0 || temp.back() != '1')
    {
        solve(n, temp + '1', ans);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    solve(n, "", ans);
    for (auto x : ans)
    {
        cout << x << endl;
    }
}
