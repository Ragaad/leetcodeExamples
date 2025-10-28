
#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

// Mirror the class you implement in main.cpp or move it to a header
class Solution {
public:
    int placeholder(int x) { return x; }
};

TEST(Template, Works){
    Solution s;
    EXPECT_EQ(s.placeholder(42), 42);
}
