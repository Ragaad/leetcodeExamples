import unittest
from solution import Solution

class TestDailyTemperatures(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,temperatures,expected):
        got=self.sol.dailyTemperatures(temperatures)
        self.assertEqual(got,expected,f"for input {temperatures} expected {expected} got {got}")
        return got==expected

    def test_examples(self):
        tests=[
            ([73,74,75,71,69,72,76,73],[1,1,4,2,1,1,0,0]),
            ([30,40,50,60],[1,1,1,0]),
            ([30,60,90],[1,1,0])
        ]

        passed=0
        for temperatures,expected in tests:
            if self.check(temperatures,expected):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)}")

if __name__ == "__main__":
    unittest.main()
