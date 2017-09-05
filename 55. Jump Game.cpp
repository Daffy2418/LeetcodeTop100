/*
*每走一步，寻找其还剩下的最大步数。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=nums[0];
        for(int i=1;i<nums.size();i++){
            if(step>0)
            {
                step-=1;
                step=max(step,nums[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};
