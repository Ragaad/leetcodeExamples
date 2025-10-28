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