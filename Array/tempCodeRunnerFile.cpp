#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int find(vector<int> &parent, int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(vector<int> &parent, int x, int y)
{
    int x_root = find(parent, x);
    int y_root = find(parent, y);
    if (x_root != y_root)
    {
        parent[x_root] = y_root;
    }
}

int solve(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        j = 1;
        while (j <= i)
        {
            if (gcd(ratings[i], ratings[j]) > 1)
            {
                unionSets(parent, i, j);
                break;
            }
            j++;
        }
    }

    int numGroups = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            numGroups++;
        }
    }

    return numGroups;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }

    sort(ratings.begin(), ratings.end());

    int numGroups = solve(ratings);
    cout << numGroups << endl;

    return 0;
}
