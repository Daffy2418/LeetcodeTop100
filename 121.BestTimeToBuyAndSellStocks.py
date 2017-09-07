class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n=len(prices)
        if n<=1:
            return 0
        minP=prices[0];profit=prices[1]-minP
        for i in range(2,n):
            if prices[i-1]<minP:
                minP=prices[i-1]
            if prices[i]-minP>profit:
                profit=prices[i]-minP
        if profit<0:
            profit=0
        return profit
