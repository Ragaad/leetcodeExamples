import unittest
import random
from solution import Solution

def brute_max_profit(prices):
    """O(n^2) reference for single-transaction max profit."""
    best = 0
    n = len(prices)
    for i in range(n):
        for j in range(i + 1, n):
            best = max(best, prices[j] - prices[i])
    return best


class TestBestTimeToBuySell121(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def check(self, prices, expected):
        got = self.sol.maxProfit(prices)
        self.assertEqual(
            got, expected,
            f"For input {prices!r}, expected {expected} but got {got}"
        )

    # --- Official-style examples & basics ---
    def test_example_1(self):
        self.check([7, 1, 5, 3, 6, 4], 5)  # buy 1, sell 6

    def test_example_2(self):
        self.check([7, 6, 4, 3, 1], 0)     # no profit possible

    def test_small_increasing(self):
        self.check([1, 2], 1)

    def test_small_decreasing(self):
        self.check([5, 4], 0)

    # --- Edges ---
    def test_empty(self):
        self.check([], 0)

    def test_single(self):
        self.check([5], 0)

    def test_flat(self):
        self.check([3, 3, 3, 3], 0)

    # --- Mixed patterns ---
    def test_valleys_peaks(self):
        # best is buy at 0, sell at 2 => profit 2
        self.check([2, 1, 2, 1, 0, 1, 2], 2)

    def test_another_mix(self):
        # best is buy at 1 (index 3), sell at 9 (index 6) => 8
        self.check([5, 2, 6, 1, 3, 4, 9, 7], 8)

    # --- Randomized vs brute-force oracle (small sizes) ---
    def test_randomized_against_oracle(self):
        random.seed(121)
        for _ in range(100):
            n = random.randint(2, 15)
            prices = [random.randint(0, 20) for _ in range(n)]
            expected = brute_max_profit(prices)
            got = self.sol.maxProfit(prices)
            self.assertEqual(
                got, expected,
                f"Random case failed: prices={prices!r}, expected={expected}, got={got}"
            )


if __name__ == "__main__":
    unittest.main()