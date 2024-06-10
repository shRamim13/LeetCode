class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxlen = 0;
        int l = 0, r = 0;
        int n = nums.size();
        while (r < n)
        {
            if (nums[r] == 0)
            {
                k--;
            } //// 1 1 1 0 0 0 0 0 0 0 1 1 1 0 1 1
            if (k < 0)
            {
                while (nums[l] != 0)
                {
                    l++;
                }
                l++;
                k++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxlen = 0;
//         int l = 0, r = 0;
//         int n = nums.size();

//         while (r < n) {
//             if (nums[r] == 0) {
//                 k--;
//             }

//             while (k < 0) {
//                 if (nums[l] == 0) {
//                     k++;
//                 }
//                 l++;
//             }

//             maxlen = max(maxlen, r - l + 1);
//             r++;
//         }

//         return maxlen;
//     }
// };
