#include "leetcode.hpp"
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    cout << s.longestCommonPrefix(vector<string>{"flower","flow","flight"}) << "\n"; // expect "fl"
    return 0;
}
