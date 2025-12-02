#include "leetcode.hpp"
#include <gtest/gtest.h>
#include <stack>
using namespace std;

// Mirror your Solution here or #include it from a header you create.
class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& T) {
        int n = (int)T.size();
        vector<int> ans(n, 0);
        stack<int> st; // stack of indices, temps strictly decreasing

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int j = st.top(); st.pop();
                ans[j] = i - j;        // first warmer day for j is i
            }
            st.push(i);
        }
        return ans;
    }
};

// Small helper to build vectors succinctly
static vector<int> V(initializer_list<int> il){ return vector<int>(il); }

TEST(DailyTemperatures, Example1){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V({73,74,75,71,69,72,76,73})),
              V({1,1,4,2,1,1,0,0}));
}

TEST(DailyTemperatures, AllIncreasing){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V({30,31,32,33})),
              V({1,1,1,0}));
}

TEST(DailyTemperatures, AllDecreasing){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V({80,79,78,77})),
              V({0,0,0,0}));
}

TEST(DailyTemperatures, FlatsAndSpikes){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V({70,70,70,71,70,72})),
              V({3,2,1,2,1,0}));
}

TEST(DailyTemperatures, SingleAndEmpty){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V({42})), V({0}));
    EXPECT_EQ(s.dailyTemperatures(vector<int>{}), vector<int>{});
}
