class Solution {
public:
    void generate_subset_subsequences(int indx, vector<int> nums, vector<int> v, vector<vector<int>>& ans){
        if(indx >= nums.size()){
            ans.push_back(v);
            return;
        }
        generate_subset_subsequences(indx + 1, nums, v, ans);
        v.push_back(nums[indx]);
        generate_subset_subsequences(indx + 1, nums, v, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int indx=0;
        generate_subset_subsequences(indx, nums, v, ans);
        return ans;
    }
};