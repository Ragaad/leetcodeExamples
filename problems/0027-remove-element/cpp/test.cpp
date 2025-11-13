#include "leetcode.hpp"
#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if ( nums.empty()) return 0;
        // TODO: two-pointer write index; skip == val
        int index=0;
        for ( int i=0; i<nums.size(); i++){
            if ( nums[i]!=val){
                nums[index]=nums[i];
                index++;
            }
        }
        return index; // replace
    }
};

static vector<int> V(initializer_list<int> il){ return vector<int>(il); }
static vector<int> prefix_sorted(const vector<int>& a, int k){
    vector<int> p(a.begin(), a.begin()+k);
    sort(p.begin(), p.end());
    return p;
}

TEST(RemoveElement, Example1){
    Solution s; vector<int> a = V({3,2,2,3});
    int k = s.removeElement(a, 3);
    EXPECT_EQ(k, 2);
    EXPECT_EQ(prefix_sorted(a, k), V({2,2}));
}

TEST(RemoveElement, Example2){
    Solution s; vector<int> a = V({0,1,2,2,3,0,4,2});
    int k = s.removeElement(a, 2);
    EXPECT_EQ(k, 5);
    EXPECT_EQ(prefix_sorted(a, k), V({0,0,1,3,4}));
}

TEST(RemoveElement, NoneToRemove){
    Solution s; vector<int> a = V({1,2,3});
    int k = s.removeElement(a, 9);
    EXPECT_EQ(k, 3);
    EXPECT_EQ(prefix_sorted(a, k), V({1,2,3}));
}

TEST(RemoveElement, AllRemoved){
    Solution s; vector<int> a = V({5,5,5});
    int k = s.removeElement(a, 5);
    EXPECT_EQ(k, 0);
}

TEST(RemoveElement, EmptyAndSingle){
    Solution s; vector<int> e;
    EXPECT_EQ(s.removeElement(e, 1), 0);
    vector<int> b = V({7});
    int k = s.removeElement(b, 7);
    EXPECT_EQ(k, 0);
}
