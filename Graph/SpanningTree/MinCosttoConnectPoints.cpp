class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 0)
            return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        vector<int> visited(n, 0);

        minHeap.push({0, 0});

        int minCost = 0;
        int edgesUsed = 0;

        while (edgesUsed < n)
        {
            auto [cost, point] = minHeap.top();
            minHeap.pop();

            if (visited[point] == 1)
                continue;

            visited[point] = 1;
            minCost += cost;
            edgesUsed++;

            for (int nextPoint = 0; nextPoint < n; ++nextPoint)
            {
                if (!visited[nextPoint])
                {
                    int nextCost = abs(points[point][0] - points[nextPoint][0]) +
                                   abs(points[point][1] - points[nextPoint][1]);
                    minHeap.push({nextCost, nextPoint});
                }
            }
        }

        return minCost;
    }
};
