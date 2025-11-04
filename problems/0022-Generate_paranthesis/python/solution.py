from typing import List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result=[]

        def backtrack(open_count,close_count,current):
            if len(current)==2*n:
                result.append(current)
                return 
            if open_count < n:
                backtrack(open_count+1,close_count,current+"(")
            if close_count < open_count:
                backtrack(open_count,close_count+1,current+")")
        
        backtrack(0,0,"")
        return result  
def solve(*args, **kwargs):
    sol=Solution()
    n=3
    print(f"The compinations for {n} paranthesis are {sol.generateParenthesis(n)}")

if __name__ == "__main__":
    solve()
