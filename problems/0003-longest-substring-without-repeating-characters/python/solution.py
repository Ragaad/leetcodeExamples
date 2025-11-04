class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        substring_chars=set()
        start=0
        result=0
        for i in range(len(s)):
            if s[i] in substring_chars:
                
                result=max(result,i-start)
                while s[start]!=s[i]:
                    substring_chars.remove(s[start])
                    start+=1
                start+=1
            else:
                substring_chars.add(s[i])
        return max(result,len(s)-start)
def solve(*args, **kwargs):
    sol=Solution()
    s="abcabcbb"
    print(f"Length of longest substring without repeating characters in {s!r} is {sol.lengthOfLongestSubstring(s)}")

if __name__ == "__main__":
    solve()
