#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.empty())
        return "";
        if (strs.size()==1)
        return strs[0];
        string longest_prefix=strs[0];
        for ( int i=1; i< strs.size(); i++){
            string current_string=strs[i];
            int j=0;
            while ( j< longest_prefix.size() &&
             j< current_string.size() &&
              longest_prefix[j]==current_string[j])
            j++;
            longest_prefix=longest_prefix.substr(0,j);

        }
        if( longest_prefix.empty())
        return "";


        // TODO: vertical scan (char by char) or sort + compare first/last
        return longest_prefix; // replace
    }
};

static vector<string> VS(initializer_list<string> il){ return {il}; }

TEST(LongestCommonPrefix, Examples) {
    Solution s;
    EXPECT_EQ(s.longestCommonPrefix(VS({"flower","flow","flight"})), "fl");
    EXPECT_EQ(s.longestCommonPrefix(VS({"dog","racecar","car"})), "");
}

TEST(LongestCommonPrefix, Edges) {
    Solution s;
    EXPECT_EQ(s.longestCommonPrefix(VS({""})), "");
    EXPECT_EQ(s.longestCommonPrefix(VS({"","abc"})), "");
    EXPECT_EQ(s.longestCommonPrefix(vector<string>{}), "");
}

TEST(LongestCommonPrefix, SingleAndAllEqual) {
    Solution s;
    EXPECT_EQ(s.longestCommonPrefix(VS({"alone"})), "alone");
    EXPECT_EQ(s.longestCommonPrefix(VS({"same","same","same"})), "same");
}

TEST(LongestCommonPrefix, Mixed) {
    Solution s;
    EXPECT_EQ(s.longestCommonPrefix(VS({"interspecies","interstellar","interstate"})), "inters");
}
