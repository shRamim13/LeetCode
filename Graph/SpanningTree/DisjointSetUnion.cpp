#include <bits/stdc++.h>
using namespace std;

int find(int parent[], int x);
void unionByRank(int parent[], int rank[], int x, int z);
void unionBySize(int parent[], int size[], int x, int z);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int parent[n + 1];
        int rank[n + 1];
        int size[n + 1];
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            if (s == "UNION" || s == "union")
            {
                int x, z;
                cin >> x >> z;
                unionByRank(parent, rank, x, z);
            }
            else if (s == "Parent" || s == "parent")
            {
                int x;
                cin >> x;
                int root = find(parent, x);
                cout << root << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

int find(int parent[], int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

void unionByRank(int parent[], int rank[], int x, int z)
{
    int rootX = find(parent, x);
    int rootZ = find(parent, z);

    if (rootX != rootZ)
    {
        if (rank[rootX] < rank[rootZ])
        {
            parent[rootX] = rootZ;
        }
        else if (rank[rootX] > rank[rootZ])
        {
            parent[rootZ] = rootX;
        }
        else
        {
            parent[rootZ] = rootX;
            rank[rootX]++;
        }
    }
}

void unionBySize(int parent[], int size[], int x, int z)
{
    int pX = find(parent, x);
    int pZ = find(parent, z);

    if (pX != pZ)
    {
        if (size[pX] < size[pZ])
        {
            parent[pX] = pZ;
            size[pZ] += size[pX];
        }
        else
        {
            parent[pZ] = pX;
            size[pX] += size[pZ];
        }
    }
}
