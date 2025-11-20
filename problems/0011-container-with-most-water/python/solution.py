from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        start=0
        end=len(height)-1
        width=end
        max_area=float('-inf')
        while start<end:
            length=min(height[start],height[end])
            max_area=max(max_area,width*length)
            if height[start]<height[end]:
                start+=1
            else:
                end-=1
            width-=1
        return max_area


def solve():
    sol=Solution()
    hieghts=[1,8,6,2,5,4,8,3,7]
    print(f"The max area is {sol.maxArea(hieghts)}")

if __name__ == "__main__":
    solve()
