#include "leetcode.hpp"
using namespace std;

// 0409. Longest Palindrome (length)
// Count chars; sum even counts + (optionally) one odd as center.
class Solution {
public:
    int longestPalindrome(const string& s) {
        if (s.empty()) return 0;
        array<int, 128> cnt{};  // ASCII
        for (unsigned char c : s) cnt[c]++;

        int len = 0;
        bool hasOdd = false;
        for (int x : cnt) {
            len += (x / 2) * 2;     // take even part
            if (x % 2) hasOdd = true;
        }
        return hasOdd ? len + 1 : len;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    cout << sol.longestPalindrome("abccccdd") << "\n"; // 7
    return 0;
}
