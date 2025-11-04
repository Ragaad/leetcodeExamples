from typing import List
import sys
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited={}
        for i,num in enumerate(nums):
            missing=target-num
            if missing in visited:
                return [visited[missing],i]
            visited[num]=i
def solve(*args, **kwargs):
    s=Solution()
    nums=[2,7,11,15]
    target=9
    print(f"For the list {nums} the numbers at {s.twoSum(nums,target)} adds up to target {target}")

if __name__ == "__main__":
    solve()
