#include "leetcode.hpp"
#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

/* ===== Solution hook =====
 * Option A (easy): paste your threeSum implementation into the class below.
 * Option B (clean): move Solution to a header (e.g., solution_0015.hpp) and
 *                   replace this class with:  #include "solution_0015.hpp"
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end()); // sort the array O(n^2)
        int i=0;
        int n=nums.size()-1;
        for ( i=0; i< n; i++){
            if ( i>0 && nums[i]==nums[i+1]) continue;
        int target=-nums[i];
        int l=i+1;
        int r=n-1;
        while( l< r){
            int sum = nums[l]+nums[r];
            if ( target==sum)
            result.push_back({nums[i],nums[l],nums[r]});

            while( nums[l] ==nums[l+1]) ++l;
            while( nums[r]==nums[r-1]) --r; //skip[ redundancy]
            ++l;
            --r;
           if( sum < target)
           l++;
           else 
           r--;
        }

        }

        // TODO: sort + two pointers; skip duplicates
        // Time: O(n^2), Space: O(1) extra (ignoring output)
        return result;
    }
};

/* ===== Helpers: normalize order so comparisons are stable ===== */
static vector<vector<int>> norm(vector<vector<int>> v) {
    for (auto &t : v) sort(t.begin(), t.end());
    sort(v.begin(), v.end());
    return v;
}
static vector<vector<int>> VV(initializer_list<initializer_list<int>> il) {
    vector<vector<int>> v; v.reserve(il.size());
    for (auto &row : il) v.emplace_back(row);
    return v;
}

/* ===== Optional: small brute-force oracle for tiny cases ===== */
static vector<vector<int>> brute3sum(vector<int> a) {
    sort(a.begin(), a.end());
    int n = (int)a.size();
    set<array<int,3>> uniq;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            for (int k = j+1; k < n; ++k)
                if ((long long)a[i] + a[j] + a[k] == 0)
                    uniq.insert({a[i], a[j], a[k]});
    vector<vector<int>> out;
    for (auto t : uniq) out.push_back({t[0], t[1], t[2]});
    return out;
}

/* ============================== Tests ============================== */

TEST(ThreeSum, Example) {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto got = s.threeSum(nums);
    auto want = VV({{-1,-1,2},{-1,0,1}});
    EXPECT_EQ(norm(got), norm(want));
}

TEST(ThreeSum, NoSolution) {
    Solution s;
    vector<int> nums = {1,2,3,4};
    EXPECT_EQ(norm(s.threeSum(nums)), norm(vector<vector<int>>{}));
}

TEST(ThreeSum, AllZeros) {
    Solution s;
    vector<int> nums = {0,0,0,0,0};
    auto got = s.threeSum(nums);
    auto want = VV({{0,0,0}});
    EXPECT_EQ(norm(got), norm(want));
}

TEST(ThreeSum, DuplicatesHeavy) {
    Solution s;
    vector<int> nums = {-2,-2,0,0,2,2,2,-2};
    auto got = s.threeSum(nums);
    auto want = VV({{-2,0,2}});
    EXPECT_EQ(norm(got), norm(want));
}

TEST(ThreeSum, MixedLargeSmall) {
    Solution s;
    vector<int> nums = {-4,-1,-1,0,1,2,2,-2};
    auto got = s.threeSum(nums);
    auto want = VV({{-4,2,2},{-2,0,2},{-1,-1,2},{-1,0,1}});
    EXPECT_EQ(norm(got), norm(want));
}

TEST(ThreeSum, ShortInputs) {
    Solution s;
    vector<int> a = {0,1};
    vector<int> b = {0,0};
    EXPECT_TRUE(s.threeSum(a).empty());
    EXPECT_TRUE(s.threeSum(b).empty());
}

TEST(ThreeSum, OracleTinyCases) {
    Solution s;
    vector<vector<int>> cases = {
        {-3,1,2,-1,5,-2},
        {-5,-1,0,6},
        {3,-1,-7,4,4,0},
        {0,0,0},
        {-2,-2,-2,4,0}
    };
    for (auto c : cases) {
        auto got = norm(s.threeSum(c));
        auto want = norm(brute3sum(c));
        EXPECT_EQ(got, want);
    }
}
