class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        min = prices[0]
        for i in prices:
            profit = max(profit, i - min)
            if i < min:
                min = i
        return profit