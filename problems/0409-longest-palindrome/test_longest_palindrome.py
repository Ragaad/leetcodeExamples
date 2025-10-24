import unittest
from longest_palindrome import Solution

class TestLongestPalindromeLen(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def check(self, s, expected):
        got = self.sol.longestPalindrome(s)
        self.assertEqual(got, expected, f"For input {s!r}, expected {expected} but got {got}")

    def test_examples(self):
        self.check("abccccdd", 7)   # "dccaccd" or similar
        self.check("a", 1)
        self.check("bb", 2)
        self.check("", 0)
        self.check("Aa", 1)         # case-sensitive, cannot pair
        self.check("AaBb", 1)       # any single char
        self.check("aaAA", 4)       # 'a' pairs and 'A' pairs separately
        self.check("ccc", 3)        # odd count can be center
        self.check("bananas", 5)    # pairs: 'a':2, 'n':2 -> 4 + center 1 = 5
        self.check("abccccdde", 7)  # pairs 6 + one center
        self.check("abc", 1)        # only one center possible

if __name__ == "__main__":
    unittest.main()
