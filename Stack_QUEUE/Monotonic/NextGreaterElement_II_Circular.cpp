class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int sz = nums.size();
        vector<int> ans(sz, 0);
        for (int i = 2 * sz - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % sz])
            {
                st.pop();
            }
            if (i < sz)
            {
                if (st.empty())
                    ans[i] = -1;
                else
                {
                    ans[i] = st.top();
                }
            }
            st.push(nums[i % sz]);
        }
        return ans;
    }
};

//        0 1 2 3 4 5
//     // 1 2 1 1 2 1
//     // 2-1 2 2-1-1

//          st->