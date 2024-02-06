class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> stack;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stack.empty() && stack.top() < nums2[i]) {
                stack.pop();
            }
            if (stack.empty()) {
                nextGreater[nums2[i]] = -1;
            } else {
                nextGreater[nums2[i]] = stack.top();
            }
            stack.push(nums2[i]);
        }

        vector<int> result;
        for (auto num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};