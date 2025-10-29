#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

/* Option A: keep a local copy here.
   Option B: move your Solution to a header and #include it in both main.cpp & test.cpp. */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Paste your implementation here when ready (or include from header)
        return {};
    }
};

// Helper to build vector<vector<int>> cleanly for EXPECT_EQ
static vector<vector<int>> VV(initializer_list<initializer_list<int>> il) {
    vector<vector<int>> v;
    v.reserve(il.size());
    for (auto &row : il) v.emplace_back(row);
    return v;
}

TEST(MergeIntervals, Example1) {
    Solution s;
    auto in = VV({{1,3},{2,6},{8,10},{15,18}});
    auto out = s.merge(in);
    EXPECT_EQ(out, VV({{1,6},{8,10},{15,18}}));
}

TEST(MergeIntervals, TouchingBoundariesMerge) {
    Solution s;
    auto in = VV({{1,4},{4,5}});
    auto out = s.merge(in);
    EXPECT_EQ(out, VV({{1,5}}));
}

TEST(MergeIntervals, UnsortedInput) {
    Solution s;
    auto in = VV({{5,7},{1,2},{2,4}});
    auto out = s.merge(in);
    EXPECT_EQ(out, VV({{1,4},{5,7}}));
}

TEST(MergeIntervals, SingleInterval) {
    Solution s;
    auto in = VV({{1,2}});
    auto out = s.merge(in);
    EXPECT_EQ(out, VV({{1,2}}));
}

TEST(MergeIntervals, NoOverlaps) {
    Solution s;
    auto in = VV({{1,2},{3,4},{6,7}});
    auto out = s.merge(in);
    EXPECT_EQ(out, VV({{1,2},{3,4},{6,7}}));
}

TEST(MergeIntervals, NegativesAndZeros) {
    Solution s;
    auto in = VV({{-5,-1},{-3,0},{1,1}});
    auto out = s.merge(in);
    EXPECT_EQ(out, VV({{-5,0},{1,1}}));
}
