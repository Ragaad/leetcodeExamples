#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int length=0;
        unordered_map<char,int> cnt;
        for ( int l=0,r=0; r < s.size(); r++){
            cnt[s[r]]++;
            while(cnt[s[r]]>1){
                cnt[s[l]]--;
                l++;
            }
            length=max(length,r-l+1);
        }
        return length; // replace
        // placeholder so tests fail until you implement
    }
};

TEST(LSWRC, Example_abcabcbb) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(LSWRC, Example_bbbbb) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(LSWRC, Example_pwwkew) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(LSWRC, Empty) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring(""), 0);
}

TEST(LSWRC, SingleChar) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring("a"), 1);
}

TEST(LSWRC, MixedDvdf) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring("dvdf"), 3); // "vdf"
}

TEST(LSWRC, AllASCII) {
    Solution s;
    string t; for (int c = 1; c < 128; ++c) t.push_back(char(c));
    EXPECT_EQ(s.lengthOfLongestSubstring(t), (int)t.size());
}

TEST(LSWRC, RepeatsAtEnds) {
    Solution s; EXPECT_EQ(s.lengthOfLongestSubstring("abba"), 2); // "ab" or "ba"
}
