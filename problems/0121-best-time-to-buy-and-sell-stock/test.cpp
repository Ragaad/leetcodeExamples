#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int minP = INT_MAX, best = 0;
        for (int p : prices) {
            minP = min(minP, p);
            best = max(best, p - minP);
        }
        return best;
    }
};

TEST(MaxProfit, Example1) {
    Solution s;
    EXPECT_EQ(s.maxProfit({7,1,5,3,6,4}), 5);
}

TEST(MaxProfit, MonotoneDecreasing) {
    Solution s;
    EXPECT_EQ(s.maxProfit({7,6,4,3,1}), 0);
}

TEST(MaxProfit, SingleDay) {
    Solution s;
    EXPECT_EQ(s.maxProfit({5}), 0);
}
