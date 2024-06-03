class Solution
{
public:
    int findParent(int parent[], int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = findParent(parent, parent[x]);
    }

    void unionBySize(int parent[], int sz[], int x, int y)
    {
        int pX = findParent(parent, x);
        int pY = findParent(parent, y);
        if (pX == pY)
        {
            return;
        }
        if (sz[pX] < sz[pY])
        {
            parent[pX] = pY;
            sz[pY] += sz[pX];
        }
        else
        {
            parent[pY] = pX;
            sz[pX] += sz[pY];
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }

        int parent[n];
        int sz[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }

        int xtra = 0;
        for (auto &x : connections)
        {
            int u = x[0];
            int w = x[1];
            if (findParent(parent, u) == findParent(parent, w))
            {
                xtra++;
            }
            else
            {
                unionBySize(parent, sz, u, w);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                cnt++;
            }
        }

        int neededEdges = cnt - 1;
        if (xtra >= neededEdges)
        {
            return neededEdges;
        }
        return -1;
    }
};
