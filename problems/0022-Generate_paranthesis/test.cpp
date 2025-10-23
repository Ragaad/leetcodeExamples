#include "leetcode.hpp"
#include <gtest/gtest.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

// ---- SUT (same implementation as your main.cpp) -----------------------------
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string>& res, string current_string, int opens, int closes, int n){
        if (opens == n && closes == n) {
            res.push_back(current_string);
            return;
        }
        if (opens < n) {
            backtrack(res, current_string + '(', opens + 1, closes, n);
        }
        if (closes < opens) {
            backtrack(res, current_string + ')', opens, closes + 1, n);
        }
    }
};

// ---- Helpers ----------------------------------------------------------------
static bool isValidParen(const string& s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') ++bal;
        else if (c == ')') { --bal; if (bal < 0) return false; }
        else return false; // only parentheses expected
    }
    return bal == 0;
}

static vector<string> sorted(vector<string> v) {
    sort(v.begin(), v.end());
    return v;
}

// ---- Tests ------------------------------------------------------------------

// n = 0 → {""} (edge case)
TEST(GenerateParentheses, N0_EmptyString) {
    Solution s;
    auto out = s.generateParenthesis(0);
    ASSERT_EQ(out.size(), 1u);
    EXPECT_EQ(out[0], "");
}

// n = 1 → {"()"}
TEST(GenerateParentheses, N1) {
    Solution s;
    auto out = s.generateParenthesis(1);
    vector<string> expect = {"()"};
    EXPECT_EQ(sorted(out), sorted(expect));
}

// n = 2 → {"(())","()()"}
TEST(GenerateParentheses, N2) {
    Solution s;
    auto out = s.generateParenthesis(2);
    vector<string> expect = {"(())","()()"};
    EXPECT_EQ(sorted(out), sorted(expect));
}

// n = 3 → 5 combos
TEST(GenerateParentheses, N3_ExactSet) {
    Solution s;
    auto out = s.generateParenthesis(3);
    vector<string> expect = {"((()))","(()())","(())()","()(())","()()()"};
    EXPECT_EQ(sorted(out), sorted(expect));
}

// Property tests for validity, uniqueness, and size for n = 4 (Catalan(4) = 14)
TEST(GenerateParentheses, N4_Properties) {
    Solution s;
    auto out = s.generateParenthesis(4);

    // 1) correct count
    EXPECT_EQ(out.size(), 14u);

    // 2) all strings valid and of length 8
    for (const auto& t : out) {
        EXPECT_EQ(t.size(), 8u);
        EXPECT_TRUE(isValidParen(t));
    }

    // 3) unique results
    unordered_set<string> uniq(out.begin(), out.end());
    EXPECT_EQ(uniq.size(), out.size());
}
