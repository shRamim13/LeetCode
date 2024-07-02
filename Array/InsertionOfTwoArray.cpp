// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> result;

//         // Sort both arrays
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());

//         // Use two pointers to find the intersection
//         int i = 0, j = 0;
//         while (i < nums1.size() && j < nums2.size())
//         {
//             if (nums1[i] < nums2[j])
//             {
//                 i++;
//             }
//             else if (nums1[i] > nums2[j])
//             {
//                 j++;
//             }
//             else
//             {
//                 result.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }

//         return result;
//     }
// };

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto x : nums1)
        {
            mp[x]++;
        }
        for (auto x : nums2)
        {
            if (mp[x])
            {
                ans.push_back(x);
                mp[x]--;
            }
        }
        return ans;
    }
};