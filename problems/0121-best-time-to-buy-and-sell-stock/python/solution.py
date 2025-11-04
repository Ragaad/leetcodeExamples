from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        min_price=float('inf')
        profit=0
        for price in prices:
            if price<min_price:
                min_price=price
            elif price>min_price:
                profit=max(profit,price-min_price)
    
        return profit

def solve(*args, **kwargs):
    sol=Solution()
    prices=[7,1,5,3,6,4]
    print(f"The max profit that can be achieved for this list of prices {prices} is {sol.maxProfit(prices)}")


if __name__ == "__main__":
    solve()
