class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        auto cmp = [](int a, int b)
        { return a > b; };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto x : nums)
        {
            pq.push(x);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};
