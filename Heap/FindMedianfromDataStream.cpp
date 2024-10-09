class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<>>
        min_heap;                 // Right side (larger numbers)
    priority_queue<int> max_heap; // Left side (smaller numbers)

    MedianFinder() {}

    void addNum(int num)
    {
        if (max_heap.empty() || num <= max_heap.top())
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }

        // Balance the heaps
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian()
    {
        if (max_heap.size() == min_heap.size())
        {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        else
        {
            return max_heap.top();
        }
    }
};
