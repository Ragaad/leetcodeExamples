#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string longestPalindrome(const string& s) {
        if (s.size() < 2) return s;
        int start = 0, best = 1;

        auto expand = [&](int L, int R) {
            while (L >= 0 && R < (int)s.size() && s[L] == s[R]) { --L; ++R; }
            // post-loop, [L+1, R-1] is the palindrome
            int len = R - L - 1;
            if (len > best) {
                best = len;
                start = L + 1;
            }
        };

        for (int i = 0; i < (int)s.size(); ++i) {
            expand(i, i);       // odd length
            expand(i, i + 1);   // even length
        }
        return s.substr(start, best);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    cout << sol.longestPalindrome("babad") << "\n"; // "bab" or "aba"
    return 0;
}