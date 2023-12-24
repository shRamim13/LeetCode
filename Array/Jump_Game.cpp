class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag=true;
        int mx_jmp=-1;
        for(int i=0;i<nums.size()-1;i++){
            mx_jmp=max(mx_jmp-1,nums[i]);
            if(mx_jmp<1){
                flag= false;
                break;
            }
        }
        return flag;        
    }
};