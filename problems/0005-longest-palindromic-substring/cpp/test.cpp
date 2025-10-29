#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(const string& s) {
        if (s.size() < 2) return s;
        int start = 0, best = 1;

        auto expand = [&](int L, int R) {
            while (L >= 0 && R < (int)s.size() && s[L] == s[R]) { --L; ++R; }
            int len = R - L - 1;
            if (len > best) {
                best = len;
                start = L + 1;
            }
        };

        for (int i = 0; i < (int)s.size(); ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, best);
    }
};

TEST(LongestPalindrome, Example_babad) {
    Solution s;
    string ans = s.longestPalindrome("babad");
    EXPECT_TRUE(ans == "bab" || ans == "aba");
}

TEST(LongestPalindrome, Example_cbbd) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("cbbd"), "bb");
}

TEST(LongestPalindrome, Singles) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("a"), "a");
}

TEST(LongestPalindrome, TwoCharsNoPal) {
    Solution s;
    string ans = s.longestPalindrome("ac");
    EXPECT_TRUE(ans == "a" || ans == "c");
}

TEST(LongestPalindrome, Repeated) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("aaaa"), "aaaa");
}