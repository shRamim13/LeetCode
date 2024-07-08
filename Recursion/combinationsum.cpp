class Solution
{
public:
    void solve(int indx, int sum, int target, vector<int> &v,
               vector<int> &candidates, vector<vector<int>> &ans)
    {
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }
        if (sum > target || indx >= candidates.size())
        {
            return;
        }
        // for (int i = indx; i < candidates.size(); i++) {
        //     if (i > indx && candidates[i] == candidates[i - 1]) { //for no
        //     duplicate
        //         continue;
        //     }
        //     v.push_back(candidates[i]);
        //     solve(indx + 1, sum + candidates[i], target, v, candidates, ans);
        //     v.pop_back();
        // }

        v.push_back(candidates[indx]);
        solve(indx, sum + candidates[indx], target, v, candidates, ans);
        v.pop_back();
        solve(indx + 1, sum, target, v, candidates, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        solve(0, 0, target, v, candidates, ans);
        return ans;
    }
};
// class Solution {
// public:
//     void func(int index,int target,vector<int>&candidates,vector<int>&v,vector<vector<int>>&ans){
//         if(target==0){
//             ans.push_back(v);
//             return ;
//         }
//         if(index==candidates.size()||candidates[index]-target>0){
//             return;
//         }
//         v.push_back(candidates[index]);
//         func(index,target-candidates[index],candidates,v,ans);
//         v.pop_back();
//         func(index+1,target,candidates,v,ans);
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>>ans;
//         sort(candidates.begin(),candidates.end());
//         vector<int>v;
//         int index=0;
//         func(index,target,candidates,v,ans);
//         return ans;
//     }
// };