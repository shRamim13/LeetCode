#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nearestSmallerElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result vector with -1
        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            // Pop elements from the stack while they are greater than or equal to the current element
            while (!st.empty() && st.top() >= nums[i])
            {
                st.pop();
            }
            // If stack is not empty, the top element is the nearest smaller element
            if (!st.empty())
            {
                result[i] = st.top();
            }
            // Push the current element to the stack
            st.push(nums[i]);
        }

        return result;
    }
};
