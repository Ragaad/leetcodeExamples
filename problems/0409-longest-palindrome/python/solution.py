class Solution:
    def longestPalindrome(self, s: str) -> int:
        letters=set()
        double_count=0
        for letter in s:
            if letter in letters:
                double_count+=2
                letters.remove(letter)
            else:
                letters.add(letter)
        return double_count if len(letters)==0 else double_count+1
def solve(*args, **kwargs):
   sol=Solution()
   s="abccccdd"
   print(f"The length longest substring plaindrome {s!r} is {sol.longestPalindrome(s)}")

if __name__ == "__main__":
    solve()
