class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int operations = 0;

        for (int num : nums)
        {
            int complement = k - num;
            if (freq[complement] > 0)
            {

                operations++;
                freq[complement]--;
            }
            else
            {

                freq[num]++;
            }
        }

        return operations;
    }
};


/*
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int val = nums[i] + nums[j];
            if (val == k) {
                cnt++;
                i++;
                j--;
            } else if (val < k) {
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }
};

*/
