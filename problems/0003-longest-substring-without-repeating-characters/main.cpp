#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    // Return the length of the longest substring without repeating characters.
    int lengthOfLongestSubstring(const string& s) {
        // TODO: sliding window with counts. Aim for O(n) time, O(min(n, alphabet)) space.
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
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n"; // expect 3
    return 0;
}
