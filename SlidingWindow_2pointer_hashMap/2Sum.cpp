class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end())
            {
                ans.push_back(mp[complement]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//      unordered_map<int,int>mp;
//      for(int i=0;i<nums.size();i++){
//          mp[nums[i]]=i;
//      }
//      for(int i=0;i<nums.size();i++){
//          int x=target-nums[i];
//          if(mp.count(x)&&i!=mp[x]){
//              return {i,mp[x]};
//         }
//     }
//     return {};

//     }
// };
