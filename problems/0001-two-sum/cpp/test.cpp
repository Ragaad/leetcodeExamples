
#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i=0; i<(int)nums.size(); ++i) {
            int need = target - nums[i];
            if (auto it = m.find(need); it != m.end()) return {it->second, i};
            m[nums[i]] = i;
        }
        return {};
    }
};

TEST(TwoSum, Example1) {
    Solution s;
    EXPECT_EQ(s.twoSum({2,7,11,15}, 9), (vector<int>{0,1}));
}

TEST(TwoSum, NoAnswer) {
    Solution s;
    EXPECT_TRUE(s.twoSum({1,2,3}, 100).empty());
}
