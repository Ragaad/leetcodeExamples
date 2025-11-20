import unittest
from solution import Solution
class TestMergedIntervals(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,numCourses,prerequisites,expected):
        got=self.sol.canFinish(numCourses,prerequisites)
        self.assertEqual(got,expected,
        f"For the number of courses{numCourses} with prerequisites{prerequisites} got {got} while expected {expected}")
        return got == expected
    
    def testExamples(self):
        tests=[
            ([2,[[1,0]]],True),
            ([2,[[1,0],[0,1]]],False),
            ([2,[[0,1]]],True)
        ]

        passed=0
        for test in tests:
            if self.check(test[0][0],test[0][1],test[1]):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)} ")

if __name__=="__main__":
    unittest.main()