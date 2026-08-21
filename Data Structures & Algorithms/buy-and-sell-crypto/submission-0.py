class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 1
        minv = prices[0]
        maxprofit = 0
        while i < len(prices):
            profit = prices[i] - minv

            if profit > 0 and maxprofit < profit:
                maxprofit = profit
            if prices[i] < minv:
                minv = prices[i]
            i += 1
        return maxprofit