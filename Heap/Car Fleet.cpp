class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        int fleet = 0;
        priority_queue<double> pq;
        for (auto x : v)
        {
            double tym = double(target - x.first) / (x.second);
            if (pq.empty() || tym > pq.top())
            {
                fleet++;
                pq.push(tym);
            }
        }
        return fleet;
    }
};
