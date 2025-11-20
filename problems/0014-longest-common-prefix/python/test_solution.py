import unittest
from solution import Solution
class TestMergedIntervals(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,strs,expected):
        got=self.sol.longestCommonPrefix(strs)
        self.assertEqual(got,expected,f"For the heights {strs} got {got} but expected {expected}")
        return got == expected
    
    def testExamples(self):
        tests=[
            (["flower","flow","flight"],"fl"),
            (["dog","racecar","car"],"")
        ]

        passed=0
        for test in tests:
            if self.check(test[0],test[1]):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)} ")

if __name__=="__main__":
    unittest.main()