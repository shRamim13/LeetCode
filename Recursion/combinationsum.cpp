class Solution {
public:
    void func(int index,int target,vector<int>&candidates,vector<int>&v,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(v);
            return ;
        }
        if(index==candidates.size()||candidates[index]-target>0){
            return;
        }
        v.push_back(candidates[index]);
        func(index,target-candidates[index],candidates,v,ans);
        v.pop_back();
        func(index+1,target,candidates,v,ans); 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        int index=0;
        func(index,target,candidates,v,ans);
        return ans;
    }
};