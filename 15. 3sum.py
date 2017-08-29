class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        ans=[];result=[]
        for i in range(len(nums)):
            j=i+1;k=len(nums)-1
            while j<k:
                if nums[j]+nums[k]<-nums[i]:
                    j+=1
                elif nums[j]+nums[k]>-nums[i]:
                    k-=1
                else:
                    result=[nums[i],nums[j],nums[k]]
                    if result not in ans:
                        ans.append(result)
                    j+=1;k-=1
        return ans
