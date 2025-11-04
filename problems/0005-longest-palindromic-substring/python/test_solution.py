from solution import Solution  

def run_tests():
    sol = Solution()

    tests = [
        # (input, expected_possible_outputs)
        ("babad", ["bab", "aba"]),
        ("cbbd", ["bb"]),
        ("a", ["a"]),
        ("ac", ["a", "c"]),
        ("racecar", ["racecar"]),
        ("forgeeksskeegfor", ["geeksskeeg"]),
        ("", [""]),
        ("abba", ["abba"]),
        ("abcba", ["abcba"]),
        ("abacdfgdcaba", ["aba"]),  # multiple small palindromes
    ]

    passed = 0
    for i, (s, expected) in enumerate(tests, start=1):
        result = sol.longestPalindrome(s)
        if result in expected:
            print(f"✅ Test {i} passed | Input: {s!r} | Output: {result!r}")
            passed += 1
        else:
            print(f"❌ Test {i} failed | Input: {s!r} | Output: {result!r} | Expected one of: {expected}")

    print(f"\nSummary: {passed}/{len(tests)} tests passed.")


if __name__ == "__main__":
    run_tests()