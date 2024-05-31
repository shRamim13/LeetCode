class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> e[], int S)
    {

        vector<int> distances(V, 1e9);
        distances[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto edge : e[node])
            {
                int nextNode = edge[0];
                int weight = edge[1];
                if (dist + weight < distances[nextNode])
                {
                    distances[nextNode] = dist + weight;
                    pq.push({distances[nextNode], nextNode});
                }
            }
        }

        return distances;
    }
};