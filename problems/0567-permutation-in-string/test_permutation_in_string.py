import unittest
from permutation_in_string import Solution

class TestPremutation_in_string(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()

    def check(self,s1,s2,expected):
        got=self.sol.checkInclusion(s1,s2)
        self.assertEqual(got,expected,f"for input {s1!r} and {s2!r} expected {expected!r} but got {got!r}")
        return got==expected

    def test(self):
        test_cases=[
            #(input, expected_output)
            (["ab","eidbaoo"],True),
            (["ab","eidboaoo"],False),
            (["aab","baaab"], True),
            (["abc","xy"],False),
            (["hello","ooolleoooleh"],False),
            (["a","a"],True),
            (["a","b"],False),
            (["","abc"],True),
            (["a",""],False),
            (["aaa","aaaa"],True),
            (["abcdefghijklmnopqrstuvwxyz","zyxwvutsrqponmlkjihgfedcba"],True),
            (["abc","abccba"],True)
        ]

        passed=0
        for s,expected in test_cases:
           if self.check(s[0],s[1],expected):
               passed+=1
        print(f"\nSummary: {passed}/{len(test_cases)}")

if __name__ == "__main__":
    unittest.main()
