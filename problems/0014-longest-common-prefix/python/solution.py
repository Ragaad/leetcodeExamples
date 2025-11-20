from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)<2:
            return strs[0]

        common_prefix=strs[0]
        for i in range(1,len(strs)):
            max_len=min(len(common_prefix),len(strs[i]))
            end_index=0
            while end_index<max_len and common_prefix[end_index]==strs[i][end_index]:
               end_index+=1
            common_prefix=common_prefix[:end_index]
            if not common_prefix: 
                break

        return common_prefix
def solve():
    sol=Solution()
    strs=["flower","flow","flight"]
    print(f"The longest common prefix for {strs} is {sol.longestCommonPrefix(strs)}")

if __name__ == "__main__":
    solve()
