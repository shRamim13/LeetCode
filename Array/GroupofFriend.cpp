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

int find(int parent[], int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(int parent[], int x, int y)
{
    int x_root = find(parent, x);
    int y_root = find(parent, y);
    if (x_root != y_root)
    {
        parent[x_root] = y_root;
    }
}

int solve(int ratings[], int n)
{
    int parent[n + 1];

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (gcd(ratings[i], ratings[j]) > 1)
            {
                unionSets(parent, i, j);
                break;
            }
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

    int ratings[n + 1];
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        ratings[i] = x;
    }

    sort(ratings + 1, ratings + n + 1);

    int numGroups = solve(ratings, n);
    cout << numGroups << endl;

    return 0;
}
