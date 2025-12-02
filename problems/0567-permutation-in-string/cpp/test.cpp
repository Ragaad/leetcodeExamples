#include "leetcode.hpp"
#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
 * Option A (drop-in): Keep this Solution here.
 * Option B (preferred): Move your Solution class to a header (e.g., solution_0567.hpp)
 * and replace this block with:  #include "solution_0567.hpp"
 */
class Solution {
public:
    // Return true if s2 contains any permutation of s1.
    bool checkInclusion(const string& s1, const string& s2) {
        int m = (int)s1.size(), n = (int)s2.size();
        if (m > n) return false;

        int a[26] = {0}, b[26] = {0};
        for (char c : s1) a[c - 'a']++;
        for (int i = 0; i < m; ++i) b[s2[i] - 'a']++;

        int matches = 0;
        for (int k = 0; k < 26; ++k) if (a[k] == b[k]) matches++;

        for (int i = 0; i <= n - m; ++i) {
            if (matches == 26) return true;
            if (i == n - m) break;

            int out = s2[i] - 'a';
            int in  = s2[i + m] - 'a';

            if (a[in] == b[in]) matches--;
            b[in]++;
            if (a[in] == b[in]) matches++;

            if (a[out] == b[out]) matches--;
            b[out]--;
            if (a[out] == b[out]) matches++;
        }
        return matches == 26;
    }
};

/* --------------------------- Brute-force oracle --------------------------- */
// Correct but slow: checks each window by sorting.
static bool bruteCheck(const string& s1, const string& s2) {
    int m = (int)s1.size(), n = (int)s2.size();
    if (m > n) return false;
    string t1 = s1; sort(t1.begin(), t1.end());
    for (int i = 0; i + m <= n; ++i) {
        string w = s2.substr(i, m);
        sort(w.begin(), w.end());
        if (w == t1) return true;
    }
    return false;
}

/* --------------------------------- Tests --------------------------------- */

TEST(PermutationInString, Examples) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("ab", "eidbaooo"));    // "ba"
    EXPECT_FALSE(s.checkInclusion("ab", "eidboaoo"));
    EXPECT_TRUE(s.checkInclusion("adc", "dcda"));       // "cda"
}

TEST(PermutationInString, EdgeCases) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("a", "a"));
    EXPECT_FALSE(s.checkInclusion("a", ""));            // s2 empty
    EXPECT_FALSE(s.checkInclusion("abc", "ab"));        // s2 shorter than s1
}

TEST(PermutationInString, Duplicates) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("aabc", "caaebaa"));   // contains "aabc"
    EXPECT_FALSE(s.checkInclusion("aabc", "cabea"));    // never matches counts
}

TEST(PermutationInString, TypicalNegatives) {
    Solution s;
    EXPECT_FALSE(s.checkInclusion("hello", "ooolleoooleh"));
    EXPECT_FALSE(s.checkInclusion("abc", "ccccbbbbaaaa"));
}

TEST(PermutationInString, Randomish_OracleComparisons) {
    Solution s;
    // A few deterministic inputs to cross-check against brute force.
    vector<pair<string,string>> cases = {
        {"ab", "eidbaooo"},
        {"ab", "eidboaoo"},
        {"xyz", "xyyzyzyx"},
        {"aa", "ab"},
        {"aaa", "baa"},
        {"abc", "cbaebabacd"}, // has "cba"
        {"abcd", "eidbcaooo"}, // no
    };
    for (auto& [s1, s2] : cases) {
        EXPECT_EQ(s.checkInclusion(s1, s2), bruteCheck(s1, s2)) << "s1="<<s1<<", s2="<<s2;
    }
}
