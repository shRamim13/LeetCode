class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        for (auto x : mp)
        {
            int s = x.second.size();
            for (int i = 0; i < s - 1; i++)
            {
                if (abs(x.second[i] - x.second[i + 1]) <= k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             // mp.count() will tell whatever ith index that I want, have I
//             seen
//             // it before?
//             if (mp.count(nums[i])) {
//                 // if I have already seen this number, then check for
//                 condition
//                 // abs(i - j) <= k
//                 if (abs(i - mp[nums[i]]) <= k)
//                     return true;
//             }
//             // if I have not seen this number before, insert the number with
//             its
//             // position in the map and if the number is already present in
//             the
//             // map, then update the position of that number
//             mp[nums[i]] = i;
//         }
//         // after the complete traversal, if we don't find a pair to satisfy
//         the
//         // condition, return false
//         return false;
//     }
// };