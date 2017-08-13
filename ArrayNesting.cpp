/***
嵌套数组的生成解释的很清楚了，其实就是值变成坐标，得到的数值再变坐标。那么实际上当循环出现的时候，嵌套数组的长度也不能再增加了，
而出现的这个相同的数一定是嵌套数组的首元素.
***/
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size(),res=INT_MIN;
        vector<bool> visited(n,false);
        for(int i=0;i<nums.size();++i){
            if(visited[i]) continue;
            res=max(res,helper(nums,i,visited));
        }
        return res;
    }
    
    int helper(vector<int> &nums,int start, vector<bool> &visited){
        int i=start,cnt=0;
        while(cnt==0||i!=start){
            visited[i]=true;
            i=nums[i];
            cnt++;
        }
        return cnt;
    }
};
