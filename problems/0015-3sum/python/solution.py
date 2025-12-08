# TODO: implement the Python version for this problem.

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
       

        n=len(nums)
        nums.sort()
        

        
        results=[]
        for i in range(n-2):
            if i>0 and nums[i]==nums[i-1]: 
                continue
            l=i+1
            r=n-1
            while l<r:
                sum=nums[i]+nums[l]+nums[r]
                if sum>0:
                    r-=1
                elif sum<0:
                    l+=1
                else:
                    results.append([nums[i],nums[l],nums[r]])
                    while l<r and nums[l]==nums[l+1]:
                        l+=1
                    while l<r and nums[r]==nums[r-1]:
                        r-=1
                    l+=1
                    r-=1

        return results

def solve():
    # optional runner entrypoint
    pass

if __name__ == "__main__":
    print("Implement me!")
