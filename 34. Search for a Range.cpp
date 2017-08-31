class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        int n=nums.size();
        range.push_back(findLeftMost(nums,n,target));
        range.push_back(findRightMost(nums,n,target));
        return range;
    }
    
    int findLeftMost(vector<int>& nums, int n, int target){
        int start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(target<nums[mid])
                end=mid-1;
            else if(target>nums[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        if(start>=0 && start<n && nums[start]==target) return start;
        return -1;
    }
    
    int findRightMost(vector<int>& nums, int n, int target){
        int start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(target<nums[mid])
                end=mid-1;
            else if(target>nums[mid])
                start=mid+1;
            else
                start=mid+1;
        }
        if(end>=0 && end<n && nums[end]==target) return end;
        return -1;
    }
};
