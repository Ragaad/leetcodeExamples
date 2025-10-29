import unittest
from longest_substring_without_repeating_characters import Solution

class TestLengthOfLongestSubstring(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,s,expected):
        got=self.sol.lengthOfLongestSubstring(s)
        self.assertEqual(got,expected,f"For input {s!r} got {got} but expected {expected}")
        return got==expected

    def testExamples(self):
        tests=[
            ("abcabcbb",3),
            ("bbbbb",1),
            ("pwwkew",3),
            ("au",2),
            ("",0),
            (" ",1)
        ]

        passed=0
        for test in tests:
            if self.check(test[0],test[1]):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)}")
if __name__ == "__main__":
    unittest.main()
