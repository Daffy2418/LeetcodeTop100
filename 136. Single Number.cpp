class Solution {
public:
    /*任何两个相同的数如果做异或，结果为0.*/
    int singleNumber(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
            res=res^nums[i];
        return res;
    }
};
