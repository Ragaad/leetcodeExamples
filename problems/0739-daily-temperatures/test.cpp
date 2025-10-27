#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

// Mirror your Solution here or #include it from a header you create.
class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& T) {
        // Implement in main.cpp and copy here, or factor into a header.
        return {}; // placeholder so tests fail until implemented
    }
};

static vector<int> V(initializer_list<int> il){ return vector<int>(il); }

TEST(DailyTemperatures, Example1){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V{73,74,75,71,69,72,76,73}),
              V{1,1,4,2,1,1,0,0});
}

TEST(DailyTemperatures, AllIncreasing){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V{30,31,32,33}),
              V{1,1,1,0});
}

TEST(DailyTemperatures, AllDecreasing){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V{80,79,78,77}),
              V{0,0,0,0});
}

TEST(DailyTemperatures, FlatsAndSpikes){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V{70,70,70,71,70,72}),
              V{3,2,1,2,1,0});
}

TEST(DailyTemperatures, SingleAndEmpty){
    Solution s;
    EXPECT_EQ(s.dailyTemperatures(V{42}), V{0});
    EXPECT_EQ(s.dailyTemperatures(vector<int>{}), vector<int>{});
}
