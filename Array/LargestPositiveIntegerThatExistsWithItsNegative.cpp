class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j && nums[i] < 0 && nums[j] > 0)
        {
            if (abs(nums[i]) == nums[j])
                return nums[j];
            if (abs(nums[i]) > nums[j])
                i++;
            else
                j--;
        }

        return -1;
    }
};

// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {

//         int len = nums.size();
//         int max = -1;

//         sort(nums.begin(), nums.end());

//         for (int i = len - 1; i >= 0; i--) {
//             if (binary_search(nums.begin(), nums.end(), -nums[i]))
//                 return nums[i];
//         }

//         return -1;
//     }
// };
// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         unordered_set<int> seen;

//         for (int num : nums) {
//             seen.insert(num);
//         }

//         for (int i = nums.size() - 1; i >= 0; i--) {
//             if (seen.count(-nums[i])) {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };