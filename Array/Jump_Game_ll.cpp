class Solution {
public:
    int jump(vector<int>& nums) {
        int canExplore=0;
        int lastJumpIndex=0;
        int jumpCount=0;
        for(int i=0;i<nums.size()-1;i++){
            canExplore=max(canExplore,i+nums[i]);
            if(i==lastJumpIndex){
                lastJumpIndex=canExplore;
                jumpCount++;
            }
        }
        return jumpCount;
    }
};