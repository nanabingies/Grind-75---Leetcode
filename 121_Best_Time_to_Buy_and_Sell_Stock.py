class Solution(object):
    def maxProfit(self, prices: list[int]) -> int:
        min_price = float('inf')
        max_profit = 0
    
        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = int(price - min_price)
    
        return max_profit
    
if __name__ == "__main__":
    soln = Solution()
    prices = [7,1,5,3,6,4]
    profit = soln.maxProfit(prices)
    print(f"profit : {profit}")
    
    prices = [7,6,4,3,1]
    profit = soln.maxProfit(prices)
    print(f"profit : {profit}")
    
    prices = [2,4,1]
    profit = soln.maxProfit(prices)
    print(f"profit : {profit}")
    
    prices = [2,1]
    profit = soln.maxProfit(prices)
    print(f"profit : {profit}")
    
    prices = [2,1,2,1,0,1,2]
    profit = soln.maxProfit(prices)
    print(f"profit : {profit}")
        