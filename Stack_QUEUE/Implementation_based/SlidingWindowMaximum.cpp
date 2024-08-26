class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Pair stores (value, index)
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            // Push the current element and its index into the heap
            maxHeap.push({nums[i], i});

            // Remove elements that are outside the current window
            while (maxHeap.top().second <= i - k)
            {
                maxHeap.pop();
            }

            // Start adding to result when the first window is formed
            if (i >= k - 1)
            {
                result.push_back(maxHeap.top().first);
            }
        }
        return result;
    }
};
