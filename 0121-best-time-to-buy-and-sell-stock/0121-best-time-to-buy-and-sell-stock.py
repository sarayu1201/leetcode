class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price=prices[0]
        max_profit=0
        for i in prices:
            min_price=min(min_price,i)
            profit= i-min_price
            max_profit=max(max_profit,profit)
        return max_profit
        