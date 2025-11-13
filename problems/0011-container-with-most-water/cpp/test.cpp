#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

// Mirror or include your C++ solution here.
class Solution {
public:
    int maxArea(const vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        while ( left< right){
            
                int h= min( height[left],height[right]);
                int w=abs(right-left);
                area=max(area, w*h);
            
            if ( height[left] < height[right])
            left++;
            else 
            right--;
        }
        // TODO: two pointers from both ends; move the smaller height inward.
        // Time: O(n), Space: O(1)
        return area; // replace
    }
};

// helper
static vector<int> V(initializer_list<int> il){ return vector<int>(il); }

TEST(ContainerMostWater, Example1){
    Solution s;
    EXPECT_EQ(s.maxArea(V({1,8,6,2,5,4,8,3,7})), 49);
}

TEST(ContainerMostWater, TwoBars){
    Solution s;
    EXPECT_EQ(s.maxArea(V({1,1})), 1);
    EXPECT_EQ(s.maxArea(V({2,3})), 2);
}

TEST(ContainerMostWater, FlatHeights){
    Solution s;
    EXPECT_EQ(s.maxArea(V({2,2,2,2})), 6); // width 3 * height 2
}

TEST(ContainerMostWater, MonotonicIncreasing){
    Solution s;
    EXPECT_EQ(s.maxArea(V({1,2,3,4,5})), 6); // best is 2*3 or 3*2
}

TEST(ContainerMostWater, WithZeros){
    Solution s;
    EXPECT_EQ(s.maxArea(V({0,0})), 0);
    EXPECT_EQ(s.maxArea(V({0,2,0,2})), 4); // indices 1 and 3 -> width 2 * height 2
}

TEST(ContainerMostWater, SingleOrEmpty){
    Solution s;
    EXPECT_EQ(s.maxArea(V({5})), 0);
    EXPECT_EQ(s.maxArea(vector<int>{}), 0);
}
