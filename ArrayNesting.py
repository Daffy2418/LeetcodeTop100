'''
  A是[0 .. N - 1]的排列，可看做顶点集合V = [0 .. N - 1]，边集合E = [[i, A[i]] (i∈[0 .. N - 1])的有向图
  图的形态是一个或者多个O型的环（可以是自环），而不会出现ρ型的环
  
  值得重要的是，图在一个圈内，如果已经属于一个圈内，则没有必要再去计算，减少了计算的复杂度
'''
class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def search(idx):
            cnt = 0
            while nums[idx] >= 0:
                cnt += 1
                next = nums[idx]
                nums[idx] = -1
                idx = next
            return cnt
        ans = 0
        for x in range(len(nums)):
            if nums[x] >= 0:
                ans = max(ans, search(x))
        return ans
