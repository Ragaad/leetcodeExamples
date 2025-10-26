from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0
        min_price=prices[0]
        profit=0
        for price in prices:
            if price<min_price:
                min_price=price
            elif price>min_price:
                profit=max(profit,price-min_price)

        
        return profit