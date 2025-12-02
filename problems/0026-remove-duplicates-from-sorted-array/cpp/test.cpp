#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // TODO: two-pointer write index
        int index=1;
        for ( int i=1; i< nums.size(); i++){
            if ( nums[i]!=nums[i-1]){
                nums[index]=nums[i];
                index ++;
            }
        }
        return index; // replace
    }

};

static vector<int> V(initializer_list<int> il){ return vector<int>(il); }

TEST(RemoveDuplicates, Example1){
    Solution s; vector<int> a = V({1,1,2});
    int k = s.removeDuplicates(a);
    EXPECT_EQ(k, 2);
    EXPECT_EQ(vector<int>(a.begin(), a.begin()+k), V({1,2}));
}

TEST(RemoveDuplicates, AllDistinct){
    Solution s; vector<int> a = V({1,2,3,4});
    int k = s.removeDuplicates(a);
    EXPECT_EQ(k, 4);
    EXPECT_EQ(vector<int>(a.begin(), a.begin()+k), V({1,2,3,4}));
}

TEST(RemoveDuplicates, AllSame){
    Solution s; vector<int> a = V({5,5,5,5});
    int k = s.removeDuplicates(a);
    EXPECT_EQ(k, 1);
    EXPECT_EQ(vector<int>(a.begin(), a.begin()+k), V({5}));
}

TEST(RemoveDuplicates, Mixed){
    Solution s; vector<int> a = V({0,0,1,1,1,2,2,3,3,4});
    int k = s.removeDuplicates(a);
    EXPECT_EQ(k, 5);
    EXPECT_EQ(vector<int>(a.begin(), a.begin()+k), V({0,1,2,3,4}));
}

TEST(RemoveDuplicates, EmptyAndSingle){
    Solution s; vector<int> a1; vector<int> a2 = V({7});
    EXPECT_EQ(s.removeDuplicates(a1), 0);
    int k2 = s.removeDuplicates(a2);
    EXPECT_EQ(k2, 1);
    EXPECT_EQ(vector<int>(a2.begin(), a2.begin()+k2), V({7}));
}
