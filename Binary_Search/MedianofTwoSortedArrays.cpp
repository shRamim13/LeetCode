class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int l = 0;
        int r = m;
        while (l <= r)
        {
            int mid1 = l + (r - l) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;
            int x1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int x2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int x3 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int x4 = (mid2 == n) ? INT_MAX : nums2[mid2];
            if (x1 > x4)
            {
                r = mid1 - 1;
            }
            else
            {
                l = mid1 + 1;
            }
            if (x1 <= x4 && x2 <= x3)
            {
                if ((m + n) % 2)
                {
                    return max(x1, x2);
                }
                else
                {
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                }
            }
        }
        return -1;
    }
};