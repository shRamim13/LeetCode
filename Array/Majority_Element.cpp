class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int mjrElmnt=0,cnt=0;
        for(auto x:nums){
            if(cnt==0){
                mjrElmnt=x;
            }
            if(mjrElmnt==x){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return mjrElmnt;
    }
};
