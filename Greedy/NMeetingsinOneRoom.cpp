#include <vector>
#include <algorithm>

using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         { return (a.first != b.first) ? a.first < b.first : a.second < b.second; });

    int cnt = 0;
    int endTask = 0;
    for (const auto &x : v)
    {
        if (x.second >= endTask)
        {
            cnt++;
            endTask = x.first;
        }
    }
    return cnt;

}
