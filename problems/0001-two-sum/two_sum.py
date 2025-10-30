from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited={}
        for i,num in enumerate(nums):
            missing=target-num
            if missing in visited:
                return [visited[missing],i]
            visited[num]=i
