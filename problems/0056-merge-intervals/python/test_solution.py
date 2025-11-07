import unittest
from solution import Solution
class TestMergedIntervals(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,intervals,expected):
        got=self.sol.merge(intervals)
        self.assertEqual(got,expected,f"For the input {intervals} got {got} while expected {expected}")
        return got == expected
    
    def testExamples(self):
        tests=[
            ([[1,3],[2,6],[8,10],[15,18]],    #intervals
            [[1,6],[8,10],[15,18]]),          #expected merged intervals
            
            ([[1,4],[4,5]],
            [[1,5]]),
            
            ([[4,7],[1,4]],
            [[1,7]])
        ]

        passed=0
        for test in tests:
            if self.check(test[0],test[1]):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)} ")

if __name__=="__main__":
    unittest.main()

