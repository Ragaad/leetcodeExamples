class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)<=1:
            return s
        
        start=0
        best=1
        
        def plaindrome(l,r):
            nonlocal start,best
            while l>=0 and r<len(s) and s[r]==s[l]:
                l-=1
                r+=1

            length=r-l-1
            if length>best:
                start=l+1
                best=length

        for i in range(0,len(s)-1):
            plaindrome(i,i)
            plaindrome(i,i+1)
    
        return s[start:start+best]
