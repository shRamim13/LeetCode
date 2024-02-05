class Solution {
public:
    void func(int index,int target,vector<int>&candidates,vector<int>&v,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(v);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target){
                break;
            }
        v.push_back(candidates[i]);
        func(i+1,target-candidates[i],candidates,v,ans);
        v.pop_back();
         } 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        int index=0;
        func(index,target,candidates,v,ans);
        return ans;
    }
};