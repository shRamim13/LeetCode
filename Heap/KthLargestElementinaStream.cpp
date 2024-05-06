class KthLargest
{
public:
    int kg;
    priority_queue<int, vector<int>, greater<>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        kg = k;
        for (auto x : nums)
        {
            pq.push(x);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > kg)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */