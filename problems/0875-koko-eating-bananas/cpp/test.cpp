#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        auto hours_needed = [&](int k)->long long {
            long long hrs = 0;
            for (int p : piles) {
                hrs += (p + k - 1) / k;
                if (hrs > (long long)h) break;
            }
            return hrs;
        };
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (hours_needed(mid) <= h) r = mid;
            else                        l = mid + 1;
        }
        return l;
    }
};

TEST(KokoBananas, Examples) {
    Solution s;

    vector<int> a{3,6,7,11};  int h1 = 8;
    EXPECT_EQ(s.minEatingSpeed(a, h1), 4);

    vector<int> b{30,11,23,4,20}; int h2 = 5;
    EXPECT_EQ(s.minEatingSpeed(b, h2), 30);

    vector<int> c{30,11,23,4,20}; int h3 = 6;
    EXPECT_EQ(s.minEatingSpeed(c, h3), 23);
}

TEST(KokoBananas, SinglePileAndBounds) {
    Solution s;
    vector<int> big{1000000000};
    EXPECT_EQ(s.minEatingSpeed(big, 2), 500000000); // ceil(1e9/2)
    EXPECT_EQ(s.minEatingSpeed(big, 1), 1000000000); // must eat all in 1 hour
}

TEST(KokoBananas, ManySmallPiles) {
    Solution s;
    vector<int> v{1,1,1,1};
    EXPECT_EQ(s.minEatingSpeed(v, 4), 1); // one per hour
    EXPECT_EQ(s.minEatingSpeed(v, 2), 2); // need speed 2 to finish in 2 hours
}

TEST(KokoBananas, WhenHEqualsNumPiles) {
    Solution s;
    vector<int> v{1,2,3,4};
    // minimal k is max(v)=4 because ceil sums → 1+1+1+1 with k=4
    EXPECT_EQ(s.minEatingSpeed(v, (int)v.size()), 4);
}
