class Solution
{
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> v;
        priority_queue<P, vector<P>> pq;
        for (auto x : points)
        {
            pq.push({x[0] * x[0] + x[1] * x[1], {x[0], x[1]}});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            v.push_back({x.second.first, x.second.second});
        }
        return v;
    }
};
