/*
*快排算法,最坏情况下会退化为O(n)算法复杂度。
*其实本质是二分法。
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L=0,R=nums.size()-1;
        while(L<R){
            int left=L,right=R;
            int key=nums[left];
            while(left<right){
                while(left<right && nums[right]<key) --right;
                nums[left]=nums[right];
                while(left<right && nums[left]>=key) ++left;
                nums[right]=nums[left];
            }
            nums[left]=key;
            if(left==k-1) return nums[k-1];
            else if(left>k-1) R=left-1;
            else L=left+1;
        }
        return nums[k-1];
    }
};
