#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(const string& s) {
        if (s.empty()) return 0;
        array<int, 128> cnt{};  // ASCII
        for (unsigned char c : s) cnt[c]++;
        int len = 0;
        bool hasOdd = false;
        for (int x : cnt) {
            len += (x / 2) * 2;
            if (x % 2) hasOdd = true;
        }
        return hasOdd ? len + 1 : len;
    }
};

TEST(LongestPalindromeLen, Example_abccccdd) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("abccccdd"), 7);
}

TEST(LongestPalindromeLen, SingleChar) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("a"), 1);
}

TEST(LongestPalindromeLen, TwoSame) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("aa"), 2);
}

TEST(LongestPalindromeLen, CaseSensitive) {
    Solution s;
    // 'A' and 'a' are different; best length is 1
    EXPECT_EQ(s.longestPalindrome("Aa"), 1);
}

TEST(LongestPalindromeLen, MixedBananas) {
    Solution s;
    // b1 a3 n2 s1 -> even parts 2(n) + 2(a) = 4 + center = 5
    EXPECT_EQ(s.longestPalindrome("bananas"), 5);
}

TEST(LongestPalindromeLen, Empty) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome(""), 0);
}
