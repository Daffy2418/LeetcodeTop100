/*
*只要把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return false;
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<nums[right]){
                if(nums[mid]<target && nums[right]>=target) left=mid+1;
                else right=mid-1;
            }else if(nums[mid]>nums[right])
            {
                if(nums[mid]>target && nums[left]<=target) right=mid-1;
                else left=mid+1;
            }else right--;
        }
        return false;
    }
};
