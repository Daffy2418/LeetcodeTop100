class Solution {
public:
    /*
    *last:已经到达的最大距离
    *ret:最小步数
    *curr:使用ret+1步后，能到达的最大距离,curr=max(curr,i+nums[i])
    */
    int jump(vector<int>& nums) {
        int ret=0;
        int last=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(i>last){
                last=curr;
                ret+=1;
            }
            curr=max(curr,nums[i]+i);
        }
        return ret;
    }
};
