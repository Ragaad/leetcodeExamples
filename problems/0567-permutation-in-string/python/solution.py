import string
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1)>len(s2):
            return False
        s1_len=len(s1)
        s2_len=len(s2)
        s1_count={char:0 for char in string.ascii_lowercase}
        s2_count={char:0 for char in string.ascii_lowercase}

        for i in range(s1_len):
            s1_count[s1[i]]+=1
            s2_count[s2[i]]+=1

        matching=0
        for char in s1_count:
            if s1_count[char]==s2_count[char]:
                matching+=1

        if matching==26:
            return True

        for i in range(s1_len,s2_len):
            out_char=s2[i-s1_len]
            in_char=s2[i]
            
            if s2_count[out_char]==s1_count[out_char]:
                matching-=1
            s2_count[out_char]-=1
            if s2_count[out_char]==s1_count[out_char]:
                matching+=1

            if s2_count[in_char]==s1_count[in_char]:
                matching-=1
            s2_count[in_char]+=+1
            if s2_count[in_char]==s1_count[in_char]:
                matching+=1

            if matching==26:
                return True
        
        return False
def solve(*args, **kwargs):
    sol=Solution()
    s1="ab"
    s2="eidbaooo"
    if sol.checkInclusion(s1,s2):
        print(f"{s1!r} permutaiton is included in {s2!r}")
    else:
        print(f"{s1!r} permutaiton is not included in {s2!r}")

if __name__ == "__main__":
    solve()
