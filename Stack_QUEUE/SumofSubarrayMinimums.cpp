#include <vector>
#include <stack>
using namespace std;

const int mod = 1e9 + 7;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        vector<int> left(n), right(n);

        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] >= nums[i])
            {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            sum += (long long)nums[i] * (i - left[i]) * (right[i] - i);
            sum %= mod;
        }

        return sum;
    }
};
