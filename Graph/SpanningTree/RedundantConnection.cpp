class Solution
{
public:
    // Function to find the parent of a node with path compression
    int findParent(int node, vector<int> &parent)
    {
        if (parent[node] != node)
        {
            parent[node] = findParent(parent[node], parent);
        }
        return parent[node];
    }

    // Function to union two nodes with union by rank
    void unionNodes(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        vector<int> redundantEdge;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            int rootU = findParent(u, parent);
            int rootV = findParent(v, parent);

            if (rootU == rootV)
            {
                // Found a cycle
                redundantEdge = edge;
            }
            else
            {
                // Union the nodes
                unionNodes(u, v, parent, rank);
            }
        }

        return redundantEdge;
    }
};
