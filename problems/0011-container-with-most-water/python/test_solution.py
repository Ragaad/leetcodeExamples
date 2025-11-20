import unittest
from solution import Solution
class TestMergedIntervals(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,height,expected):
        got=self.sol.maxArea(height)
        self.assertEqual(got,expected,f"For the heights {height} got {got} but expected {expected}")
        return got == expected
    
    def testExamples(self):
        tests=[
            ([1,8,6,2,5,4,8,3,7],49),
            ([1,1],1)
        ]

        passed=0
        for test in tests:
            if self.check(test[0],test[1]):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)} ")

if __name__=="__main__":
    unittest.main()