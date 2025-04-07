#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> P;

vector<vector<int>> findPairs(int n, int m, vector<int> &arr1, vector<int> &arr2, int k)
{
    vector<vector<int>> v;
    if (n == 0 || m == 0 || k == 0)
        return v;

    priority_queue<P, vector<P>, greater<P>> pq;
    set<pair<int, int>> st;

    pq.push({arr1[0] + arr2[0], {0, 0}});
    st.insert({0, 0});

    while (k-- && !pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int i = x.second.first;
        int j = x.second.second;
        v.push_back({arr1[i], arr2[j]});

        if (i + 1 < n && st.find({i + 1, j}) == st.end())
        {
            pq.push({arr1[i + 1] + arr2[j], {i + 1, j}});
            st.insert({i + 1, j});
        }

        if (j + 1 < m && st.find({i, j + 1}) == st.end())
        {
            pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
            st.insert({i, j + 1});
        }
    }

    return v;
}
