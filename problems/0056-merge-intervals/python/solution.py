from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        result=[]
        
        for interval in intervals:
            if not result or result[-1][1]<interval[0]:
                result.append(interval)
            else:
                result[-1][1]=max(result[-1][1],interval[1])

        return result
def solve(*args, **kwargs):
    sol=Solution()
    intervals=[[1,3],[2,6],[8,10],[15,18]]
    print(f"The merged intervals for these intervals {intervals} are:\n {sol.merge(intervals)}")

if __name__ == "__main__":
    solve()
