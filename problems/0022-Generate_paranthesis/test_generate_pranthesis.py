import unittest
from typing import List

# ⬇️ Change this import to match your solution file name
from generate_pranthesis import Solution   # expects Solution.generateParenthesis(self, n: int) -> List[str]


def is_valid_paren(s: str) -> bool:
    """Check if s is a valid parenthesis string."""
    bal = 0
    for ch in s:
        if ch == '(':
            bal += 1
        else:
            bal -= 1
        if bal < 0:
            return False
    return bal == 0


# Catalan numbers C_n for n = 0..8 (we'll use 1..5 here)
CATALAN = {0: 1, 1: 1, 2: 2, 3: 5, 4: 14, 5: 42, 6: 132, 7: 429, 8: 1430}


class TestGenerateParentheses(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_n1_exact(self):
        got = sorted(self.sol.generateParenthesis(1))
        expected = ["()"]
        self.assertEqual(got, expected)

    def test_n2_exact(self):
        got = sorted(self.sol.generateParenthesis(2))
        expected = sorted(["(())", "()()"])
        self.assertEqual(sorted(set(got)), expected)  # order-insensitive, unique

    def test_n3_exact(self):
        got = sorted(self.sol.generateParenthesis(3))
        expected = sorted(["((()))", "(()())", "(())()", "()(())", "()()()"])
        self.assertEqual(sorted(set(got)), expected)

    def test_n4_properties(self):
        got = self.sol.generateParenthesis(4)
        # correct count (Catalan), uniqueness, and validity
        self.assertEqual(len(got), CATALAN[4], "Wrong number of combinations for n=4")
        self.assertEqual(len(got), len(set(got)), "Duplicates found for n=4")
        for s in got:
            self.assertTrue(is_valid_paren(s), f"Invalid sequence for n=4: {s!r}")

    def test_n5_properties(self):
        got = self.sol.generateParenthesis(5)
        self.assertEqual(len(got), CATALAN[5], "Wrong number of combinations for n=5")
        self.assertEqual(len(got), len(set(got)), "Duplicates found for n=5")
        for s in got:
            self.assertTrue(is_valid_paren(s), f"Invalid sequence for n=5: {s!r}")

    def test_non_negative_n(self):
        # LeetCode uses n >= 1, but if you choose to support n=0:
        # Expected one empty string (Catalan(0)=1). If your solution disallows 0, you can skip this.
        if 0 in CATALAN:
            got = self.sol.generateParenthesis(0)
            self.assertEqual(got, [""])


if __name__ == "__main__":
    unittest.main()