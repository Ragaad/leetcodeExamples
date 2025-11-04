from typing import List
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result=[0]*len(temperatures)

        high=[]
        for i in range(len(temperatures)):
            while high and temperatures[i]>temperatures[high[-1]]:
                lowest_high=high.pop()
                result[lowest_high]=i-lowest_high
            high.append(i)
            

        return result
def solve(*args, **kwargs):
    sol=Solution()
    temperatures=[73,74,75,71,69,72,76,73]
    print(f"The number of days to wait to get a warmer temprature following for", 
    f"this daily temparatures {temperatures} is {sol.dailyTemperatures(temperatures)}")

if __name__ == "__main__":
    solve()
