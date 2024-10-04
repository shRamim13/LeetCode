class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

// class Solution
// {
// public:
//     int findPeakElement(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n == 1)
//             return 0;
//         if (nums[0] > nums[1])
//             return 0;
//         if (nums[n - 1] > nums[n - 2])
//             return n - 1;
//         int l = 0;
//         int r = n - 2;
//         while (l = r)
//         {
//             int mid = (l + r) / 2;
//             if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
//             {
//                 return mid;
//             }
//             if (nums[mid - 1] < nums[mid])
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }
//         return -1;
//     }
// };